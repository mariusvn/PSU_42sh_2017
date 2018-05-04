/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** tmp.c created: 12/04/18 14:11
*/

#include <minishell.h>
#include <linkify.h>
#include <stdlib.h>
#include <my.h>

lk_node_t *cut_operations(char *input)
{
	char **input_split = split_shell(input, ";");
	lk_node_t *root = NULL;

	for (int i = 0; input_split[i]; i++) {
		if (!root)
			root = lk_create_node(input_split[i]);
		else
			lk_append_data(root, input_split[i]);
	}
	return (root);
}

void exec_prog(char *input, ressources_t *rsces)
{
	char **args;
	int pos;

	input = clean_str_pipe(input);
	args = split_shell(input, " \t");
	pos = is_builtin(args[0]);
	if (pos != -1) {
		get_builtins()[pos].fnc(args, rsces);
	} else
		execute_prog(args, rsces);
}