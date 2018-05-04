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
#include <minishell.h>
#include <my.h>

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

bool is_sc(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	else
		return (false);
}

char *clean_str(char *str)
{
	int i = 0;
	int pos = 0;
	char *ret;

	ret = malloc(sizeof(char) * my_strlen(str) + 2);
	for (i = 0; str[i]; i += 1) {
		if (str[i + 1] && is_sc(str[i]) && !is_sc(str[i + 1])) {
			ret[pos] = ' ';
			pos += 1;
		}
		if (!is_sc(str[i])) {
			ret[pos] = str[i];
			pos += 1;
		}
	}
	ret[pos] = '\0';
	free(str);
	return (ret);
}

bool is_check_perm(char *path, char *zero)
{
	int perm;

	if (!is_exists(path)) {
		my_printf("%s: Command not found.\n", zero);
		return (false);
	}
	perm = access(path, X_OK);
	if (perm == -1) {
		my_printf("%s: Permission denied.\n", zero);
		return (false);
	}
	return (true);
}