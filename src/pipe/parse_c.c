/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** parse_c.c created: 12/04/18 14:16
*/

#include <my.h>
#include <minishell.h>

op_type_t parse_node_c(char *str, int i, bt_node_t *node, ressources_t *rsces)
{
	int a[2] = {i, 0};

	if (str[i] == '|' && str[i + 1])
	{
		parse_node_step(str, node, a, rsces);
		return (PIPE);
	}
	if (str[i] == '>' && str[i + 1])
	{
		parse_node_step(str, node, a, rsces);
		return (REDIRECT_RIGHT);
	}
	if (str[i] == '<' && str[i + 1])
	{
		parse_node_step(str, node, a, rsces);
		return (REDIRECT_LEFT);
	}
	return (NONE);
}