/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** header
*/


<<<<<<< HEAD
#ifndef MINISHELL_1
#define MINISHELL_1
=======
#ifndef SHELL_H_
	#define SHELL_H_

#define DEBUG
>>>>>>> dev

#include <stdbool.h>

typedef struct ressources_s {
	char **env;
	char ***last_env;
} ressources_t;

typedef struct builtin_s {
	char *command;
	int (*fnc)(char **, ressources_t *);
} builtin_t;

#include <parse.h>

char *get_env_var(char *name, char **env);

char *get_current_dir(ressources_t *rsces);

int cd(char **args, ressources_t *rsces);

int exit_shell(char **args, ressources_t *rsces);

int env_shell(char **args, ressources_t* rsces);

void execute_prog(char **args, ressources_t* rsces);

int setenv_shell(char **args, ressources_t *rsces);

int unsetenv_shell(char **args, ressources_t *rsces);

bool is_right_var(char *name, char *env, int *pos);

char **dup_double_array(char **arr);

void init_empty_env(ressources_t *rsces);

bool is_exists(char *path);

bool is_check_perm(char *path, char *zero);

char **split_shell(char *input, char *separators);

void exec_prog(char *input, ressources_t *rsces);

int is_builtin(char *fnc_name);

builtin_t *get_builtins(void);

char *find_in_path(ressources_t *rsces, char *str);

void handle_return(ressources_t *rsces, int *ret);

void my_signal(void);

char *clean_str(char *str);


#endif