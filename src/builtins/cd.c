/*
** EPITECH PROJECT, 2017
** minishell1_2017
** File description:
** cd.c created: 02/01/18 18:15
*/

#include <unistd.h>
#include <my.h>
#include <minishell.h>
#include <limits.h>

char *setenv_cd(char *var, char *content, ressources_t* rsces)
{
	char **nargs = malloc(sizeof(char *) * 4);
	char *ret;

	nargs[0] = "";
	nargs[1] = my_strdup(var);
	nargs[2] = my_strdup(content);
	nargs[3] = NULL;
	ret = get_env_var(var, rsces->env);
	setenv_shell(nargs, rsces);
	return (ret);
}

int minus(ressources_t *rsces)
{
	char *chor;
	char *pwd = get_env_var("PWD", rsces->env);
	char *pos = malloc(PATH_MAX);

	if (pwd)
		chor = setenv_cd("OLDPWD", pwd, rsces);
	else {
		getcwd(pos, PATH_MAX);
		chor = setenv_cd("OLDPWD", pos, rsces);
	}
	chdir(chor);
	return (0);
}

void to_home(ressources_t *rsces)
{
	char *home = get_env_var("HOME", rsces->env);

	if (!home) {
		my_putstr("cd: No home directory.\n");
		return;
	}
	chdir(home);
}

int move(char **args, char *pos, ressources_t *rsces)
{
	int ret = chdir(args[1]);

	if (ret == 0 && pos) {
		setenv_cd("OLDPWD", pos, rsces);
		getcwd(pos, PATH_MAX);
		if (pos)
			setenv_cd("PWD", pos, rsces);
	} else {
		my_putstr(args[1]);
		my_putstr(": No such file or directory.\n");
		return (1);
	}
	return (0);
}

int cd(char **args, ressources_t *rsces)
{
	char *pos = malloc(PATH_MAX);

	if (my_array_length((void **) args) == 1) {
		to_home(rsces);
		return (0);
	} else if (my_array_length((void **) args) != 2) {
		my_putstr("cd: Too many arguments.\n");
		return (-1);
	}
	if (my_strlen(args[1]) == 1 && args[1][0] == '-')
		return (minus(rsces));
	getcwd(pos, PATH_MAX);
	return (move(args, pos, rsces));
}