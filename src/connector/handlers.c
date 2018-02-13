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
	(void)sig;

	data->pid2 = si->si_pid;
	my_putstr("\nenemy connected\n\n");
	data->connected = true;
}

void data_handler(int signo)
{
	if (signo == SIGUSR1) {
		data->data += 1;
	} else if (signo == SIGUSR2) {
		data->received = true;
	}
}

void response_handler(int signo)
{
	if (signo == SIGUSR1) {
		data->data += 1;
	} else if (signo == SIGUSR2) {
		data->received = true;
	}
}
