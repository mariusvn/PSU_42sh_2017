/*
** EPITECH PROJECT, 2017
** linkify
** File description:
** linkify.c created: 13/03/18 16:21
*/

#include "linkify.h"
#include <stdlib.h>

lk_node_t *lk_create_node(void *data)
{
	lk_node_t *elemen = malloc(sizeof(*elemen));

	elemen->data = data;
	elemen->next = NULL;
}

bool lk_append_node(lk_node_t *root, lk_node_t *new)
{
	if (!root)
		return (false);
	for (; root->next; root = root->next);
	root->next = new;
	return (true);
}

bool lk_append_data(lk_node_t *root, void *data)
{
	bool a;

	if (!root)
		return (false);
	lk_node_t *new_elem = lk_create_node(data);
	a = lk_append_node(root, new_elem);
	if (!a)
		return (false);
	return (true);
}

int lk_get_length(lk_node_t *root)
{
	int res = 0;

	for (; root; root = root->next)
		res ++;
	return (res);
}

void *lk_get_at_index(lk_node_t *root, int index)
{
	int i = 0;

	for (; root && i < index; root = root->next)
		i++;
	if (root)
		return (root);
	return (NULL);
}