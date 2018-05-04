/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** semicolon.c created: 15/04/18 13:15
*/

#include <shell.h>
#include <stdlib.h>

/// Just execute all command child of semicolon
void execute_semicolon(bt_node_t *node, ressources_t *rsces)
{
	execute_cmd_node(node->child[0], NULL, rsces);
	execute_cmd_node(node->child[1], NULL, rsces);
}