/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** parse_b.c created: 12/04/18 14:11
*/

#include <shell.h>
#include <my.h>

/// Check if the node is a SEMICOLON type
op_type_t parse_node_a(bt_node_t *node, char *str, ressources_t *rsces)
{
	for (int i = my_strlen(str) - 1; i >= 0; i--) {
		if (str[i] == ';' && str[i + 1]) {
			parse_node_step(str, node, (int[2]) {i, 0}, rsces);
			return (SEMICOLON);
		}
	}
	return (NONE);
}

/// Check if the node is a DOUBLE_REDIRECT
op_type_t parse_node_b(bt_node_t *node, char *str, ressources_t *rsces)
{
	op_type_t type;

	for (int i = my_strlen(str) - 1; i >= 0; i--) {
		if (str[i + 1] && i >= 1 && (str[i - 1] == '>'
					     && str[i] == '>'))
		{
			parse_node_step(str, node, (int[2]) {i, 1}, rsces);
			return (DOUBLE_REDIRECT_RIGHT);
		}
		if (str[i + 1] && i >= 1 && (str[i - 1] == '<'
					     && str[i] == '<'))
		{
			parse_node_step(str, node, (int[2]) {i, 1}, rsces);
			return (DOUBLE_REDIRECT_LEFT);
		}
		type = parse_node_c(str, i, node, rsces);
		if (type != NONE)
			return (type);
	}
	return (NONE);
}

/// Check type of the node
void parse_node(bt_node_t *node, ressources_t *rsces)
{
	char *str = my_strdup(clean_str(node->sentence));
	op_type_t stop = NONE;

	stop = parse_node_a(node, str, rsces);
	if (stop == NONE)
		stop = parse_node_b(node, str, rsces);
	node->type = stop;
	//if (node->type == NONE)
	//	exec_prog(node->sentence, rsces);
	free(str);
}

/// Main parsing function
bt_node_t *parse_input(char *input, ressources_t *rsces)
{
	bt_node_t *root = create_bt_node();

	root->sentence = input;
	parse_node(root, rsces);
	return (root);
}