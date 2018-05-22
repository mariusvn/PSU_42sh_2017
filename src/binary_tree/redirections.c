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
#include <string.h>
#include <zconf.h>

void execute_dr_left(bt_node_t *node, ressources_t *rsces)
{
	char *s;
	char *tmp;
	int fd = open(".", __O_TMPFILE | O_RDWR, S_IRWXU);

	do {
		my_putstr("? ");
		s = clean_str(get_next_line(0));
		tmp = my_str_append(s, (strcmp(s, clean_str\
		(node->child[1]->sentence)) == 0) ? "\0" : "\n");
		if ((strcmp(s, clean_str(node->child[1]->sentence)) != 0))
			write(fd, tmp, strlen(tmp));
		else
			break;
	} while (1);
	node->child[0]->in = fd;
	lseek(fd, SEEK_SET, 0);
	execute_bt_node(node->child[0], NULL, rsces);
	close(fd);
}

void execute_dr_right(bt_node_t *node, ressources_t *rsces)
{
	if (is_exists(clean_str(node->child[1]->sentence)) == true) {
		node->child[0]->out = open(clean_str(node->child[1]->sentence)\
		, O_RDWR | O_APPEND);
		execute_bt_node(node->child[0], NULL, rsces);
		close(node->child[0]->out);
	} else {
		node->child[0]->out = open(clean_str(node->child[1]->sentence)\
		, O_CREAT | O_RDWR, S_IRWXU);
		execute_bt_node(node->child[0], NULL, rsces);
		close(node->child[0]->out);
	}
}

void execute_r_right(bt_node_t *node, ressources_t *rsces)
{
	if (is_exists(clean_str(node->child[1]->sentence)) == true) {
		remove(clean_str(node->child[1]->sentence));
		node->child[0]->out = open(clean_str(node->child[1]->sentence)\
		, O_CREAT | O_RDWR, S_IRWXU);
		execute_bt_node(node->child[0], NULL, rsces);
		close(node->child[0]->out);
	} else {
		node->child[0]->out = open(clean_str(node->child[1]->sentence)\
		, O_CREAT | O_RDWR, S_IRWXU);
		execute_bt_node(node->child[0], NULL, rsces);
		close(node->child[0]->out);
	}

}

void execute_r_left(bt_node_t *node, ressources_t *rsces)
{
	char *str = clean_str(node->child[1]->sentence);

	if (is_exists(str) == true) {
		node->child[0]->in = open(str, O_RDWR);
		execute_bt_node(node->child[0], NULL, rsces);
		close(node->child[0]->in);
	} else {
		fprintf(stderr\
		, "42sh: aucun fichier ou dossier de ce type: %s\n", str);
	}
}
