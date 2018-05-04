/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** env.c created: 03/01/18 10:55
*/

#include <minishell.h>
#include <my.h>

int env_shell(char **args, ressources_t* rsces)
{
	int i = 0;

	if (!rsces || !rsces->env)
		return (0);
	for (; rsces->env[i]; i += 1) {
		my_putstr(rsces->env[i]);
		my_putchar('\n');
	}
	return (0);
}