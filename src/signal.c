/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** signal.c created: 15/04/18 18:02
*/

#include <signal.h>
#include <minishell.h>
#include <stdlib.h>

void sig_handler(int sig)
{
	char *a = "exit 0";
	exit_shell(split_shell(a, " "), NULL);
}

void my_signal(void)
{
	signal(SIGSEGV, sig_handler);
	signal(SIGINT, sig_handler);
}