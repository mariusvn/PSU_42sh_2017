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
	node->child[0]->out = open(clean_str(node->child[1]->sentence), O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
	execute_bt_node(node->child[0], NULL, rsces);
	close(node->child[0]->out);
}

void execute_r_left(bt_node_t *node, ressources_t *rsces)
{
	char *str = clean_str(node->child[1]->sentence);

	if (is_exists(str) == true) {
		node->child[0]->in = open(str, O_RDWR);
		execute_bt_node(node->child[0], NULL, rsces);
		close(node->child[0]->in);
	} else {
		fprintf(stderr, "42sh: aucun fichier ou dossier de ce type: %s\n", str);
	}
}