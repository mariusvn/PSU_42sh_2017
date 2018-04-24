/*
** EPITECH PROJECT, 2017
** minishell2_2017
** File description:
** operate.c created: 13/04/18 14:12
*/

#include <minishell.h>
#include <my.h>

/*
 	SEMICOLON,
	REDIRECT_LEFT,
	REDIRECT_RIGHT,
	DOUBLE_REDIRECT_LEFT,
	DOUBLE_REDIRECT_RIGHT,
	PIPE,
	OPERATION,
	NONE
 */

void execute_bt_node(bt_node_t *node, bt_node_t *nodeb, ressources_t *rsces)
{
	switch(node->type) {
		case NONE:
			execute_cmd_node(node, nodeb, rsces);
			break;
		case SEMICOLON:
			execute_semicolon(node, rsces);
			break;
		case PIPE:
			execute_pipe(node, rsces);
			break;
		default:
			my_putstr("not handled\n");
	}
}