/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** pipe.c created: 12/04/18 11:47
*/

#include <shell.h>
#include <unistd.h>
#include <my.h>
#include <fcntl.h>
#include <sys/wait.h>

/// execute a pipe node in the binary tree
void execute_pipe(bt_node_t *node, ressources_t *rsces)
{
	int fd[2];

	if (node->type != PIPE)
		return;
	pipe(fd);
	node->child[0]->out = fd[1];
	node->child[1]->in = fd[0];
	node->child[0]->fds[0] = fd[0];
	node->child[0]->fds[1] = fd[1];
	node->child[1]->fds[0] = fd[0];
	node->child[1]->fds[1] = fd[1];
	if (node->out != 1)
		node->child[1]->out = node->out;
	if (node->in != 0)
		node->child[0]->in = node->in;
	execute_bt_node(node->child[1], node->child[0], rsces);
}

/// execute a command when we already forked
void execute_cmd_forked(char **args, ressources_t *rsces)
{
	char *pgrm;
	bool perm;

	if (my_array_length((void **) args) == 0)
		return;
	pgrm = find_in_path(rsces, args[0]);
	(!pgrm) ? (pgrm = args[0]) : "";
	perm = is_check_perm(pgrm, args[0]);
	if (!perm) {
		exit(0);
	}
	execve(pgrm, args, rsces->env);
}

/// Second part of execute_cmd_node (fd general handling)
static void execute_cmd_node_b(bt_node_t *node, ressources_t *rsces)
{
	char **args;

	if (node->in != 0) {
		close(0);
		dup(node->in);
	}
	if (node->out != 1) {
		close(1);
		dup(node->out);
	}
	close(node->fds[0]);
	close(node->fds[1]);
	args = split_shell(node->sentence, " \t");
	execute_cmd_forked(args, rsces);
}

/// Execute a builtin
void execute_builtin(bt_node_t *node, int pos, ressources_t *rsces)
{
	int saves[2];
	char **args;

	saves[0] = dup(0);
	saves[1] = dup(1);
	if (node->in != 0) {
		close(0);
		dup(node->in);
	}
	if (node->out != 1) {
		close(1);
		dup(node->out);
	}
	close(node->fds[0]);
	close(node->fds[1]);
	args = split_shell(node->sentence, " \t");
	get_builtins()[pos].fnc(args, rsces);
	close(0);
	dup(saves[0]);
	close(1);
	dup(saves[1]);
}

/// Execute a node with NONE type (standard command, no pipe, etc ...)
void execute_cmd_node(bt_node_t *node, bt_node_t *next, ressources_t *rsces)
{
	int pid;
	char **args = split_shell(node->sentence, " \t");
	int pos;

	if (my_array_length((void **)args) == 0)
		return;
	pos = is_builtin(args[0]);
	if (pos != -1) {
		execute_builtin(node, pos, rsces);
		return;
	}
	pid = fork();
	if (pid == 0) {
		execute_cmd_node_b(node, rsces);
	}
	close(node->fds[0]);
	if (next)
		execute_bt_node(next, NULL, rsces);
	close(node->fds[1]);
	wait(&pid);
}