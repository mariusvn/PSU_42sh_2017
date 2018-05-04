/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** main.c
*/

#include <my.h>
#include <minishell.h>
#include <unistd.h>

static builtin_t builtins[] = {
	{"cd", cd},
	{"exit", exit_shell},
	{"env", env_shell},
	{"setenv", setenv_shell},
	{"unsetenv", unsetenv_shell},
	{NULL, NULL}
};

ressources_t *init_rsces(char **env)
{
	ressources_t *rsces = malloc(sizeof(*rsces));

	rsces->env = env;
	if (!rsces->env[1])
		init_empty_env(rsces);
	return (rsces);
}

int is_builtin(char *fnc_name)
{
	int i;

	for (i = 0; builtins[i].command != NULL; i += 1) {
		if (my_strcmp(fnc_name, builtins[i].command) == 0)
			return (i);
	}
	return (-1);
}

void exit_verif(void)
{
	if (isatty(0))
		my_putstr("exit\n");
	exit(0);
}

builtin_t *get_builtins(void)
{
	return (builtins);
}

int main(int ac, char **av, char **env)
{
	char **dupenv = dup_double_array(env);
	char *path = malloc(1);
	char *entry;
	ressources_t *rsces = init_rsces(dupenv);
	bt_node_t *root;

	my_signal();
	rsces->last_env = &env;
	while (1) {
		free(path);
		path = get_current_dir(rsces);
		if (isatty(0))
			my_printf("\x1B[32m%s\x1B[0m > ", path);
		entry = get_next_line(0);
		if (!entry)
			exit_verif();
		entry = clean_str(entry);
		root = parse_input(entry, rsces);
		execute_bt_node(root, NULL, rsces);
	}
}
