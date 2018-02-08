/*
** EPITECH PROJECT, 2018
** navy_2017
** File description:
** navy functions
*/

# include "navy.h"

static void free_all(data_t *data)
{
	free_p1(data->p1);
	free_p2(data->p2);
	free(data);
}

int game_manager(data_t *data)
{
	my_putstr("my_pid: ");
	my_put_nbr(data->pid);
	my_putchar('\n');
	return (data->status);
}

int navy(int ac, char **av)
{
	data_t *data = config_struct(ac, av);
	int st;

	if (data == NULL) {
		my_puterr("Malloc failed. Aborded.\n", false);
		return (84);
	}
	if (data->status != 0) {
		free_all(data);
		return (data->status);
	}
	st = game_manager(data);
	free_all(data);
	return (st);
}
