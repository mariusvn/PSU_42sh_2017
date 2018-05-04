/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** parse.c created: 11/04/18 12:58
*/

#include <minishell.h>
#include <linkify.h>
#include <stdlib.h>
#include <my.h>

bt_node_t *create_bt_node(void)
{
	bt_node_t *res = malloc(sizeof(*res));

	res->child[0] = NULL;
	res->child[1] = NULL;
	res->sentence = NULL;
	res->type = NONE;
	res->validated = false;
	res->parent = NULL;
	res->in = 0;
	res->out = 1;
	res->fds[0] = -1;
	res->fds[1] = -1;
	return (res);
}

void create_child_nodes(bt_node_t *parent)
{
	parent->child[0] = create_bt_node();
	parent->child[1] = create_bt_node();
	parent->child[0]->parent = parent;
	parent->child[1]->parent = parent;
}

char *clean_str_pipe(char *str)
{
	char **a = split_shell(str, " \t");
	char *res = malloc(sizeof(*res) * my_strlen(str) + 1);
	int act_idx_str = 0;

	for (int i = 0; a[i]; i++) {
		for (int j = 0; a[i][j]; j++) {
			res[act_idx_str] = a[i][j];
			act_idx_str ++;
		}
		if (a[i + 1]) {
			res[act_idx_str] = ' ';
			act_idx_str++;
		}
	}
	res[act_idx_str] = '\0';
	return (res);
}

void parse_node_step(char *sentence, bt_node_t *parent,
		     int i[2], ressources_t *rsces)
{
	create_child_nodes(parent);
	sentence[i[0] - i[1]] = '\0';
	parent->child[0]->sentence = my_strdup(sentence);
	parse_node(parent->child[0], rsces);
	parent->child[1]->sentence = my_strdup(&sentence[i[0] + 1]);
	parse_node(parent->child[1], rsces);
}
