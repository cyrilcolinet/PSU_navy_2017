/*
** EPITECH PROJECT, 2018
** navy_2017
** File description:
** navy functions
*/

# include "navy.h"

int navy(int ac, char **av)
{
	data_t *data = config_struct(ac, av);
	int exit_status;

	if (data == NULL) {
		my_puterr("Malloc failed. Aborded.\n", false);
		return (84);
	}
	my_putstr("my_pid: ");
	my_put_nbr(data->pid);
	my_putchar('\n');
	free_p1(data->p1);
	free_p2(data->p2);
	exit_status = data->status;
	free(data);
	return (exit_status);
}
