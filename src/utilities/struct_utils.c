/*
** EPITECH PROJECT, 2018
** navy_2017
** File description:
** struct_utils function
*/

# include "navy.h"

void free_p1(p1_t *playerOne)
{
	free(playerOne);
}

void free_p2(p2_t *playerTwo)
{
	free(playerTwo);
}

p1_t *config_struct_p1(char **av)
{
	p1_t *p1 = malloc(sizeof(*p1));

	if (p1 == NULL)
		return (NULL);

	p1->p2_pid = 0;

	return (p1);
}

p2_t *config_struct_p2(char **av)
{
	p2_t *p2 = malloc(sizeof(*p2));

	if (p2 == NULL)
		return (NULL);

	p2->p1_pid = my_atoi(av[1]);

	return (p2);
}

data_t *config_struct(int ac, char **av)
{
	data_t *data = malloc(sizeof(*data));

	if (data == NULL)
		return (NULL);

	data->status = 0;
	data->type = ((ac == 3) ? playerTwo : playerOne);
	data->pid = getpid();

	if (data->type == playerOne) {
		data->p1 = config_struct_p1(av);
		data->p2 = NULL;

		if (data->p1 == NULL)
			return (NULL);
	} else {
		data->p1 = NULL;
		data->p2 = config_struct_p2(av);

		if (data->p2 == NULL)
			return (NULL);
	}

	return (data);
}