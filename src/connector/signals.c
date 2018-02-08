/*
** EPITECH PROJECT, 2018
** navy
** File description:
** signals function
*/

# include "navy.h"

void sig_get_sender(int signum, siginfo_t *si)
{
	printf ("Sending PID: %d, UID: %d\n", si->si_pid, si->si_uid);
}