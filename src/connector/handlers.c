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

void data_handler(int sig, siginfo_t *si, void *ptr)
{
	(void)sig;
	(void)ptr;

	if (si->si_signo == SIGUSR1) {
		data->data++;
	} else if (si->si_signo == SIGUSR2) {
		printf("Final data received: %d\n", data->data);
		data->received = true;
		data->data = 0; // reset !!!! NOT HERE
	}
}