/*
** EPITECH PROJECT, 2018
** navy
** File description:
** connector functions
*/

# include "navy.h"

bool connector(data_t *data)
{
	if (data->type == playerOne) {
		my_putstr("waiting for enemy connection...\n");

		if (pause() == -1) {
			printf("%d\n", errno);
			exit(84); // forbidden
		}
	} else {

	}

	return (true);
}