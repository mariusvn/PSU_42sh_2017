/*
** EPITECH PROJECT, 2017
** 42sh
** File description:
** Cheaty file
*/

#include <signal.h>
#include <shell.h>
#include <stdlib.h>

void sig_handler(int sig)
{
	char *a = "exit 0";
	exit_shell(split_shell(a, " "), NULL);
}

void my_signal(void)
{
#ifdef DEBUG
	//signal(SIGSEGV, sig_handler);
	//signal(SIGINT, sig_handler);
#endif
}