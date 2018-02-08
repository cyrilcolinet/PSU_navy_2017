/*
** EPITECH PROJECT, 2018
** navy
** File description:
** connector functions
*/

# include "navy.h"

int configure_sig(int sig, void *action)
{
	sigact_t old;
	sigact_t act;

	if (sigaction(sig, NULL, &old) == -1)
		return (-1);

	act.sa_handler = action;
	//sigemptyset(&act.sa_mask);
	//act.sa_flags = 0;

	if (sigaction(sig, &act, NULL) == -1)
		return (-1);

	return (0);
}

/*void configure_def_signal(int sig, data_t *data)
{
	sigact_t act;
	sigact_t old;

	if (sig == SIGUSR1) {
		sigaction(SIGUSR1, NULL, &old);
		act.sa_handler = sig_get_sender;
	} else if (sig == SIGUSR2) {
		// To be continued
	}

	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	data->status = sigaction(sig, &act, &old);
}*/

bool connector(void)
{
	//configure_def_signal(SIGUSR1, data);
	//configure_def_signal(SIGUSR2, data);

	if (configure_sig(SIGUSR1, sig_get_sender) == -1)
		return (false);
	
	if (data->type == playerOne) {
		my_putstr("waiting for enemy connection...\n");

		if (pause() == -1) {
			my_putstr("\nenemy connected.\n");
		}
	} else {

	}

	return (true);
}