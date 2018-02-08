/*
** EPITECH PROJECT, 2018
** navy_2017
** File description:
** navy functions
*/

# include "navy.h"

static void free_all(data_t *data)
{
	if (data->p1->map != NULL)
		my_freetab(data->p1->map);
	else if (data->p2->map != NULL)
		my_freetab(data->p2->map);
	free_p1(data->p1);
	free_p2(data->p2);
	free(data);
}

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
	exit_status = data->status;
	free_all(data);
	return (exit_status);
}
