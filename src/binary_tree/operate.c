/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** operate.c created: 13/04/18 14:12
*/

#include <shell.h>
#include <parse.h>
#include <my.h>

/*
	This file handle a node
 	It's the main function that we call to execute the binary tree.

 	Here are all node types :

 	SEMICOLON,			;
	REDIRECT_LEFT,			<
	REDIRECT_RIGHT,			>
	DOUBLE_REDIRECT_LEFT,		<<
	DOUBLE_REDIRECT_RIGHT,		>>
	PIPE,				|
	NONE				std command
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
		case REDIRECT_RIGHT:
			execute_r_right(node, rsces);
			break;
		case REDIRECT_LEFT:
			execute_r_left(node, rsces);
			break;
		default:
			my_putstr("not handled\n");
	}
}