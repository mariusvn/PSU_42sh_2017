/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** exit.c created: 02/01/18 18:59
*/

#include <stdlib.h>
#include <my.h>
#include <minishell.h>

bool is_digit(char c, int pos)
{
	if (pos == 0)
		if (!((c >= '0' && c <= '9') || c == '-'))
			return (false);
		else
			return (true);
	else {
		if (!(c >= '0' && c <= '9'))
			return (false);
		else
			return (true);
	}
}

short is_number(char *str)
{
	bool is_num = true;
	bool is_first_text = false;

	if (my_strlen(str) == 0)
		return (-1);
	if (!is_digit(str[0], 0))
		is_first_text = true;
	for (int i = 0; str[i]; i += 1) {
		if (!is_digit(str[i], i))
			is_num = false;
	}
	if (is_num && !is_first_text)
		return (0);
	if (!is_num && !is_first_text)
		return (1);
	if (!is_num && is_first_text)
		return (2);
	return (1);
}

int exit_nbr(char **args, ressources_t *rsces)
{
	short nbrid = is_number(args[1]);

	if (nbrid == 0) {
		my_putstr("exit\n");
		exit(my_getnbr(args[1]));
	} else if (nbrid == 1) {
		my_putstr("exit: Badly formed number.\n");
	} else {
		my_putstr("exit: Expression Syntax.\n");
	}
	return (1);
}

int exit_shell(char **args, ressources_t *rsces)
{
	int len = my_array_length((void **) args);

	if (len == 1) {
		my_putstr("exit\n");
		exit(0);
	} else if (len == 2) {
		exit_nbr(args, rsces);
		return (1);
	} else {
		my_putstr("exit: Expression Syntax.\n");
		return (1);
	}
}