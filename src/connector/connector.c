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

	act.sa_handler = action;

	if (sigaction(sig, &act, NULL) == -1)
		return (-1);

	return (0);
}

bool connector(void)
{
	if (configure_sig(SIGUSR1, sig_get_sender) == -1)
		return (false);
	
	if (data->type == playerOne) {
		my_putstr("waiting for enemy connection...\n");
		pause();
	}

	return (true);
}