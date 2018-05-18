/*
** EPITECH PROJECT, 2018
** PSU_42sh_2017
** File description:
** rafter handling
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <my.h>
#include <errno.h>
#include <parse.h>

void execute_r_right(bt_node_t *node, ressources_t *rsces)
{
	if (is_exists(node->child[1]->sentence) == true) {
		node->child[0]->out = open(node->child[1]->sentence, O_RDWR);
		printf("fd child1: %d\n", node->child[0]->out);
	} else if( is_exists(node->child[1]->sentence) == false) {
		node->child[0]->out = open(node->child[1]->sentence, O_CREAT | O_RDWR, S_IRWXU);
		printf("fd child1: %d\n", node->child[0]->out);
	}
	execute_bt_node(node->child[0], NULL, rsces);
	close(node->child[0]->out);
}