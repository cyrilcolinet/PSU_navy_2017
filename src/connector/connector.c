/*
** EPITECH PROJECT, 2018
** navy
** File description:
** connector functions
*/

# include "navy.h"

int get_receiver_pid(void)
{
	int pid = 0;

	if (data->type == playerOne) {
		pid = data->p1->p2_pid;
	} else {
		pid = data->p2->p1_pid;
	}

	return (pid);
}

bool send_data(int sig, char *column)
{
	int bit = get_case_number(column);
	int loop;

	for (loop = 0; loop < bit; loop++) {
		if (kill(get_receiver_pid(), sig) < 0) {
			write(2, "Unable to send signal to receiver.\n", 35);
			return (false);
		}
	}

	return (true);
}

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

	signal(SIGUSR1, sigusr_receiver);
	signal(SIGUSR2, sigusr_receiver);

	return (true);
}