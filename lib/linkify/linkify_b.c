/*
** EPITECH PROJECT, 2017
** linkify
** File description:
** linkify_b.c created: 14/03/18 12:19
*/

#include "linkify.h"
#include <stdlib.h>

lk_node_t *lk_remove_data(lk_node_t *root, void *data)
{
	lk_node_t *tmp = NULL;
	lk_node_t *root_node = root;

	if (root->data == data) {
		tmp = root->next;
		free(root);
		return (tmp);
	}
	while (root) {
		if (root->data == data) {
			tmp->next = root->next;
			free(root);
			return (root_node);
		}
		tmp = root;
		root = root->next;
	}
	return (root_node);
}