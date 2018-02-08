/*
** EPITECH PROJECT, 2018
** navy
** File description:
** connector functions
*/

# include "navy.h"

int configure_sig(int sig, void *action)
{
	sigact_t act;

	if (sig == SIGUSR1 || sig == SIGUSR2) {
		act.sa_handler = action;

		if (sigaction(sig, &act, NULL) == -1)
			return (-1);

		return (0);
	}

	return (-1);
}

bool connector(void)
{
	if (configure_sig(SIGUSR1, sig_get_sender) == -1)
		return (false);
	
	if (data->type == playerOne) {
		my_putstr("waiting for enemy connection...\n");
		pause();
	} else {
		if (kill(data->p2->p1_pid, SIGUSR1) < 0) {
			write(2, "Unable to send signal.\n", 23);
			return (false);
		}
	}

	return (true);
}