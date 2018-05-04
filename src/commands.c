/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** commands.c created: 03/01/18 11:14
*/

#include <minishell.h>
#include <unistd.h>
#include <my.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdbool.h>

char *put_end_slash(char *path)
{
	char *npath;

	if (path[my_strlen(path) - 1] != '/') {
		npath = my_str_append(path, "/");
		free(path);
		path = npath;
	}
	return (path);
}

bool is_exists(char *path)
{
	int fd = open(path, O_RDONLY);

	if (fd != -1) {
		close(fd);
		return (true);
	}
	return (false);
}

char *find_in_path(ressources_t *rsces, char *str)
{
	char *path_str = get_env_var("PATH", rsces->env);
	char **path = my_split(path_str, ':');
	int i = 0;
	int fd;
	char *npath;

	for (; path[i]; i += 1) {
		path[i] = put_end_slash(path[i]);
		npath = my_str_append(path[i], str);
		fd = open(npath, O_RDONLY);
		if (fd != -1) {
			close(fd);
			return (npath);
		}
	}
	return (NULL);
}

void handle_return(ressources_t *rsces, int *ret)
{
	if (!(!WIFEXITED(*ret) && !WEXITSTATUS(*ret)))
		return;
	if (WTERMSIG(*ret) == SIGSEGV) {
		if (WCOREDUMP(*ret))
			my_putstr("Segmentation fault (core dumped)\n");
		else
			my_putstr("Segmentation fault\n");
	}
	if (WTERMSIG(*ret) == SIGFPE) {
		if (WCOREDUMP(*ret))
			my_putstr("Floating exception (core dumped)\n");
		else
			my_putstr("Floating exception\n");
	}
}

void execute_prog(char **args, ressources_t* rsces)
{
	char *pgrm;
	int forker;
	int ret;
	bool perm;

	if (my_array_length((void **) args) == 0)
		return;
	pgrm = find_in_path(rsces, args[0]);
	(!pgrm) ? (pgrm = args[0]) : "";
	perm = is_check_perm(pgrm, args[0]);
	if (!perm)
		return;
	forker = fork();
	if (forker == 0) {
		execve(pgrm, args, rsces->env);
	} else {
		wait(&ret);
		handle_return(rsces, &ret);
	}
}