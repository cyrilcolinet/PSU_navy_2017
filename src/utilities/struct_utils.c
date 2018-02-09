/*
** EPITECH PROJECT, 2018
** navy_2017
** File description:
** struct_utils function
*/

# include "navy.h"

void free_struct(void)
{
	my_freetab(data->info);
	my_freetab(data->map);
	my_freetab(data->enemy);
	free(data);
}

bool config_struct(int ac, char **av)
{
	data = malloc(sizeof(*data));

	if (data == NULL)
		return (false);
	data->type = ((ac == 3) ? playerTwo : playerOne);
	data->pid = getpid();
	data->info = NULL;
	data->map = NULL;
	data->enemy = NULL;
	data->winner = 0;
	data->data = -1;
	data->received = false;
	if (data->type == playerOne) {
		data->pid2 = -1;
		data->status = map_management(av[1]);
	} else {
		data->pid2 = my_atoi(av[1]);
		data->status = map_management(av[2]);
	}
	return (true);
}
