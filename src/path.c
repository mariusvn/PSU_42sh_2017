/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** path.c created: 02/01/18 17:28
*/

#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <shell.h>
#include <my.h>
#include <stdio.h>

/// check if the env contains HOME (if yes, set the home path)
bool is_containing_home(ressources_t *rsces, char **path)
{
	char *homepath = get_env_var("HOME", rsces->env);
	int i = 0;
	char *pathp = *path;
	char *save = *path;

	if (!homepath)
		return (false);
	if (my_strlen(pathp) < my_strlen(homepath))
		return (false);
	for (; homepath[i] && pathp[i]; i += 1) {
		if (homepath[i] != pathp[i])
			return (false);
	}
	pathp = &pathp[i - 1];
	pathp[0] = '~';
	*path = my_strdup(pathp);
	free(save);
	free(homepath);
	return (true);
}

char *get_current_dir(ressources_t *rsces)
{
	char *pos = malloc(sizeof(char) * PATH_MAX);

	pos = getcwd(pos, PATH_MAX);
	is_containing_home(rsces, &pos);
	return (pos);
}

/// Check the perms (as well ^^)
bool is_check_perm(char *path, char *zero)
{
	int perm;

	if (!is_exists(path)) {
		printf("%s: Command not found.\n", zero);
		return (false);
	}
	perm = access(path, X_OK);
	if (perm == -1) {
		printf("%s: Permission denied.\n", zero);
		return (false);
	}
	return (true);
}