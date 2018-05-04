/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** split.c created: 01/04/18 13:22
*/

#include <stdlib.h>
#include <minishell.h>
#include <my.h>
#include <stdbool.h>

int *get_words_idx(char *input, char *separators);
bool is_empty(char *input, char *separators);

bool is_separator(char c, char const *separators)
{
	for (int i = 0; separators[i]; i++)
		if (separators[i] == c)
			return (true);
	return (false);
}

int get_words_nbr(char *input, char *separators)
{
	int ret = 0;

	for (int i = 0; input[i + 1]; i++) {
		if (!is_separator(input[i], separators) &&
		    is_separator(input[i + 1], separators))
			ret ++;
	}
	if (!is_separator(input[my_strlen(input) - 1], separators))
		ret ++;
	return (ret);
}

int get_word_len(char *input, int idx, char *separators)
{
	int ret = 0;

	if (idx > my_strlen(input))
		return (0);
	for (int i = idx; input[i] &&
			  !is_separator(input[i], separators); i++) {
		ret ++;
	}
	return (ret);
}

char *get_word_at(char *input, int idx, char *separators)
{
	int len = get_word_len(input, idx, separators);
	char *ret = malloc(sizeof(char) * (len + 1));

	for (int i = 0; i < len; i++)
		ret[i] = input[i + idx];
	ret[len] = '\0';
	return (ret);
}

char **split_shell(char *input, char *separators)
{
	int words_nbr;
	char **ret;
	int *idx_array;

	if (is_empty(input, separators)) {
		ret = malloc(sizeof(char *));
		ret[0] = NULL;
		return (ret);
	}
	words_nbr = get_words_nbr(input, separators);
	ret = malloc(sizeof(char *) * (words_nbr + 1));
	idx_array = get_words_idx(input, separators);
	ret[words_nbr] = NULL;
	for (int i = 0; i < words_nbr; i++) {
		ret[i] = get_word_at(input, idx_array[i], separators);
	}
	free(idx_array);
	return (ret);
}