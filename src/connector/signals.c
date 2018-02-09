/*
** EPITECH PROJECT, 2018
** navy
** File description:
** signals function
*/

# include "navy.h"

void get_player_pid(void)
{
	sigact_t act;

	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = pid_handler;

	if (sigaction(SIGUSR1, &act, NULL)) {
		write(2, "Invalid sigaction method.\n", 26);
		data->pid2 = -1;
		return;
	}
}

void get_sended_data(void)
{
	sigact_t act;

	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = data_handler;

	if (sigaction(SIGUSR1, &act, NULL) < 0 || sigaction(SIGUSR2, &act, NULL) < 0) {
		write(2, "Invalid sigaction method.\n", 26);
		data->received = -1;
		return;
	}
}