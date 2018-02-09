/*
** EPITECH PROJECT, 2018
** navy
** File description:
** handlers connection
*/

# include "navy.h"

void pid_handler(int sig, siginfo_t *si, void *ptr)
{
	(void)ptr;

	data->pid2 = si.si_pid;
	my_putstr("\nenemy connected\n");
	data->connected = true;
}