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
	int sigusr1 = -1;
	int sigusr2 = -1;

	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = data_handler;

	sigusr1 = sigaction(SIGUSR1, &act, NULL);
	sigusr2 = sigaction(SIGUSR2, &act, NULL);

	if (sigusr1 < 0 || sigusr2 < 0) {
		write(2, "Invalid sigaction method.\n", 26);
		data->received = false;
		return;
	}
}

void get_response(void)
{
	sigact_t act;
	int sigusr1 = -1;
	int sigusr2 = -1;

	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	act.sa_sigaction = response_handler;

	sigusr1 = sigaction(SIGUSR1, &act, NULL);
	sigusr2 = sigaction(SIGUSR2, &act, NULL);

	if (sigusr1 < 0 || sigusr2 < 0) {
		write(2, "Invalid sigaction method.\n", 26);
		data->received = false;
		return;
	}
}