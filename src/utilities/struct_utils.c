/*
** EPITECH PROJECT, 2018
** navy_2017
** File description:
** struct_utils function
*/

# include "navy.h"

void free_p1(p1_t *playerOne)
{
	if (playerOne != NULL) {
		my_freetab(playerOne->map);
		free(playerOne);
	}
}

void free_p2(p2_t *playerTwo)
{
	if (playerTwo != NULL) {
		my_freetab(playerTwo->map);
		free(playerTwo);
	}
}

p1_t *config_struct_p1(char **av)
{
	p1_t *p1 = malloc(sizeof(*p1));

	if (p1 == NULL)
		return (NULL);

	p1->p2_pid = 0;
	p1->map = NULL;
	data->status = map_management(av[1]);

	return (p1);
}

p2_t *config_struct_p2(char **av)
{
	p2_t *p2 = malloc(sizeof(*p2));

	if (p2 == NULL)
		return (NULL);

	p2->p1_pid = my_atoi(av[1]);
	p2->map = NULL;
	data->status = map_management(av[2]);

	return (p2);
}

bool config_struct(int ac, char **av)
{
	data = malloc(sizeof(*data));

	if (data == NULL)
		return (false);
	data->status = 0;
	data->type = ((ac == 3) ? playerTwo : playerOne);
	data->pid = getpid();
	if (data->type == playerOne) {
		data->p1 = config_struct_p1(av);
		data->p2 = NULL;
		if (data->p1 == NULL)
			return (false);
	} else {
		data->p1 = NULL;
		data->p2 = config_struct_p2(av);
		if (data->p2 == NULL)
			return (false);
	}

	return (true);
}
