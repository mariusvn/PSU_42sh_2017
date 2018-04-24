/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** dup.c created: 16/01/18 11:14
*/

#include <my.h>
#include <minishell.h>

char **dup_double_array(char **arr)
{
	int len = my_array_length((void **) arr);
	char **res = malloc(sizeof(char *) * (len + 1));
	int i = 0;

	if (!arr)
		return NULL;
	for (; i < len; i += 1) {
		res[i] = my_strdup(arr[i]);
	}
	res[i] = NULL;
	return (res);
}

void init_empty_env(ressources_t *rsces)
{
	char *path[4] = {"setenv", "PATH", \
	"/usr/local/sbin:/usr/local/bin:/usr/sbin:"
		"/usr/bin:/sbin:/bin:/snap/bin", NULL};
	char *pwd[4] = {"setenv", "PWD", "/", NULL};
	char *oldpwd[4] = {"setenv", "OLDPWD", "/", NULL};

	rsces->env = malloc(sizeof(char *) * 4);
	for (int i = 0; i < 5; i += 1) {
		rsces->env[i] = NULL;
	}
	setenv_shell(path, rsces);
	setenv_shell(pwd, rsces);
	setenv_shell(oldpwd, rsces);
	rsces->env[3] = NULL;
}