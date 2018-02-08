/*
** EPITECH PROJECT, 2018
** navy
** File description:
** signals function
*/

# include "navy.h"

void sig_get_sender(int sig, siginfo_t *si)
{
	if (sig == SIGUSR1 || sig == SIGUSR2) {
		if (data->type == playerOne) {
			data->p1->p2_pid = si->si_pid;
		} else {
			data->p2->p1_pid = si->si_pid;
		}

		printf("\n%d\n", si->si_pid);
		my_putstr("\nenemy connected\n");
	}
}