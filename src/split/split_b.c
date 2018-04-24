/*
** EPITECH PROJECT, 2017
** PSU_minishell2_2017
** File description:
** split_b.c created: 03/04/18 10:38
*/

#include <stdbool.h>
#include <my.h>

bool is_separator(char c, char const *separators);
int get_words_nbr(char *input, char *separators);

int *get_words_idx(char *input, char *separators)
{
	int word_nbr = get_words_nbr(input, separators);
	int *res = malloc(sizeof(int) * (word_nbr + 1));
	int act_edit = 0;

	res[word_nbr] = -1;
	if (!is_separator(input[0], separators)) {
		res[act_edit] = 0;
		act_edit ++;
	}
	for (int i = 0; input[i + 1]; i++) {
		if (is_separator(input[i], separators) &&
		    !is_separator(input[i + 1], separators)) {
			res[act_edit] = i + 1;
			act_edit ++;
		}
	}
	return (res);
}

bool is_empty(char *input, char *separators)
{
	if (my_strlen(input) == 0)
		return (true);
	for (int i = 0; input[i]; i++)
		if (!is_separator(input[i], separators))
			return (false);
	return (true);
}

void free_str_array(char **str_array)
{
	for (int i = 0; str_array[i]; i++)
		free(str_array[i]);
}