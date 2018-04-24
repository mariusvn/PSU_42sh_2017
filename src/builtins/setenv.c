/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** setenv.c created: 03/01/18 14:33
*/

#include <minishell.h>
#include <stdlib.h>
#include <my.h>
#include <stdbool.h>

int add_env_var(char *new_env, ressources_t *rsces)
{
	char **new_envb;
	int i;
	int j;

	new_envb = malloc(sizeof(*new_envb) * \
	(my_array_length((void **)rsces->env) + 2));
	for (i = 0; rsces->env[i]; i += 1) {
		new_envb[i] = malloc(sizeof(char) *
				     my_strlen(rsces->env[i]) + 1);
		for (j = 0; rsces->env[i][j]; j += 1) {
			new_envb[i][j] = rsces->env[i][j];
		}
		new_envb[i][j] = '\0';
	}
	new_envb[i] = new_env;
	new_envb[i + 1] = NULL;
	rsces->env = new_envb;
	return (0);
}

char *setenv_b(char **args, int len, ressources_t *rsces, bool *is_set_var)
{
	char *new_env = my_str_append(args[1], "=");
	int pos = 0;

	if (len == 3)
		new_env = my_str_append(new_env, args[2]);
	for (int i = 0; rsces->env[i]; i += 1) {
		if (is_right_var(args[1], rsces->env[i], &pos)) {
			*is_set_var = true;
			rsces->env[i] = new_env;
		}
	}
	return (new_env);
}

int setenv_shell(char **args, ressources_t *rsces)
{
	char *new_env;
	bool is_set_var = false;
	int len = my_array_length((void **)args);

	if (len > 3) {
		my_putstr("setenv: Too many arguments.\n");
		return (1);
	} else if (len == 1) {
		env_shell(args, rsces);
		return (0);
	}
	new_env = setenv_b(args, len, rsces, &is_set_var);
	if (!is_set_var)
		return (add_env_var(new_env, rsces));
	return (0);
}
