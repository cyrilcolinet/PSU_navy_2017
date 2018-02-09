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
	data->status = 0;
	data->type = ((ac == 3) ? playerTwo : playerOne);
	data->pid = getpid();

	if (data->type == playerOne)
		data->pid2 = -1;
	else
		data->pid2 = my_atoi(av[1]);

	data->info = NULL;
	data->map = NULL;
	data->enemy = NULL;

	return (true);
}
