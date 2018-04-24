/*
** EPITECH PROJECT, 2017
** linkify
** File description:
** linkify.h
*/

#ifndef LINKIFY_H_
#define LINKIFY_H_

#include <stdbool.h>

typedef struct lk_node_s {
	void *data;
	struct lk_node_s *next;
} lk_node_t;

/// Create a node
///
/// Use this to create a root of a linked list
/// \param data data to give at the root
/// \return root node
lk_node_t *lk_create_node(void *data);

/// add data at the end of a linked list
/// \param root root node
/// \param data data to add
/// \return true if worked, false if not
bool lk_append_data(lk_node_t *root, void *data);

/// return the length of a linked list
/// \param root root node
/// \return lentgh of the linked list
int lk_get_length(lk_node_t *root);

/// get an item of the linked list
/// \param root root node
/// \param index index
/// \return data of the item, if cannot access to index, return NULL
void *lk_get_at_index(lk_node_t *root, int index);

//////////////////////////////// DO NOT USE ////////////////////////////////

/// Do not use
bool lk_append_node(lk_node_t *root, lk_node_t *new);

#endif /* !LINKIFY_H */
