/*
** EPITECH PROJECT, 2017
** minishell2_2017
** File description:
** parse.h created: 12/04/18 14:12
*/

#ifndef MINISHELL2_2017_PARSE_H_
#define MINISHELL2_2017_PARSE_H_

#include "shell.h"

typedef enum op_type_e {
	SEMICOLON,
	REDIRECT_LEFT,
	REDIRECT_RIGHT,
	DOUBLE_REDIRECT_LEFT,
	DOUBLE_REDIRECT_RIGHT,
	PIPE,
	OPERATION,
	NONE
} op_type_t;

typedef struct binary_tree_node_s {
	op_type_t type;
	struct binary_tree_node_s *parent;
	struct binary_tree_node_s *child[2];
	int in;
	int out;
	int fds[2];
	bool validated;
	char *sentence;
} bt_node_t;

bt_node_t *parse_input(char *input, ressources_t *rsces);

void parse_node(bt_node_t *node, ressources_t *rsces);

bt_node_t *create_bt_node(void);

void create_child_nodes(bt_node_t *parent);

void parse_node_step(char *sentence, bt_node_t *parent,
		     int i[2], ressources_t *rsces);

op_type_t parse_node_a(bt_node_t *node, char *str, ressources_t *rsces);

op_type_t parse_node_b(bt_node_t *node, char *str, ressources_t *rsces);

op_type_t parse_node_c(char *str, int i, bt_node_t *node, ressources_t *rsces);

void execute_bt_node(bt_node_t *node, bt_node_t *nodeb, ressources_t *rsces);

void execute_pipe(bt_node_t *node, ressources_t *rsces);

void execute_cmd_node(bt_node_t *node, bt_node_t *next, ressources_t *rsces);

void execute_semicolon(bt_node_t *node, ressources_t *rsces);

#endif /* !MINISHELL2_2017_PARSE_H_ */
