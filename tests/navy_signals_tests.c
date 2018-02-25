/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** navy_signals_tests functions
*/

# include "units.h"

Test(signals, unexistant_pid, .init = redirect_std)
{
	char *args[3];
	char pid[5];
	int res = -1;

	srand(time(NULL));
	sprintf(pid, "%d", (rand() % (29999 - 999) + 999));

	if (pid == NULL)
		return;

	args[0] = "./navy";
	args[1] = pid;
	args[2] = "maps/pos2";
	res = navy_main(3, args);

	cr_assert_eq(res, 84);
}
