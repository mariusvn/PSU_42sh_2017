/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** environment.c created: 02/01/18 16:55
*/

#include <stdbool.h>
#include <my.h>

bool is_right_var(char *name, char *env, int *pos)
{
	int i = 0;

	for (; name[i] && env[i]; i += 1) {
		if (name[i] != env[i])
			return (false);
	}
	if (env[i] == '=') {
		*pos = i + 1;
		return (true);
	} else
		return (false);
}

char *get_env_var(char *name, char **env)
{
	int pos;

	for (int i = 0; env[i]; i += 1) {
		if (is_right_var(name, env[i], &pos)) {
			return (my_strdup(&env[i][pos]));
		}
	}
	return (NULL);
}