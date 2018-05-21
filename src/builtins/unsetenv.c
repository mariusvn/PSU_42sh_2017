/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** unsetenv.c created: 03/01/18 14:55
*/

#include <shell.h>
#include <stdlib.h>
#include <my.h>
#include <stdbool.h>

char **unsetenv_b(ressources_t *rsces, int *i, char **args)
{
	char **new_env = malloc(sizeof(char *) * \
	(my_array_length((void**)rsces->env) + 1));
	int j;
	bool okay;
	int pos = 0;

	for (*i = 0; rsces->env[*i]; *i += 1) {
		okay = true;
		for (j = 0; args[1][j]; j += 1)
			if (rsces->env[*i][j] != args[1][j]) {
				okay = false;
				break;
			}
		if (!okay) {
			new_env[pos] = rsces->env[*i];
			pos += 1;
		}
	}
	*i = pos;
	return (new_env);
}

int unsetenv_shell(char **args, ressources_t *rsces)
{
	int len = my_array_length((void**)args);
	char **new_env = NULL;
	int i = 0;

	if (len < 2) {
		my_putstr("unsetenv: Too few arguments.\n");
		return (1);
	}
	new_env = unsetenv_b(rsces, &i, args);
	new_env[i] = NULL;
	rsces->env = new_env;
	return (0);
}