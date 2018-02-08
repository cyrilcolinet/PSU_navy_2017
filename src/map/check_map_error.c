/*
** EPITECH PROJECT, 2018
** check_map_error
** File description:
** navy
*/

#include "navy.h"

int check_map_error(data_t *data, char *buff)
{
	if (my_strlen(buff) < 31) {
		my_puterr("map invalid !!", false);
		return (-1);
	}
	data->info = my_strtok(buff, '\n');
	for (int i = 0; data->info[i] != NULL; i++)
		printf("A%s\n", data->info[i]);
	return (0);
}
