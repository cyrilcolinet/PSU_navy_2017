/*
** EPITECH PROJECT, 2018
** check_boat_error
** File description:
** navy
*/

#include "navy.h"

static int cas1(int i)
{
	if (data->info[i][6] > data->info[i][3]) {
		if (data->info[i][0] - 48 -
		(data->info[i][6] - data->info[i][3] + 1) != 0)
			return (-1);
	}
	if (data->info[i][6] < data->info[i][3]) {
		if (data->info[i][0] - 48 -
		(data->info[i][3] - data->info[i][6] +1) != 0)
			return (-1);
	}
	return (0);
}

static int cas2(int i)
{
	if (data->info[i][5] > data->info[i][2]) {
		if (data->info[i][0] - 48 -
		(data->info[i][5] - data->info[i][2] +1) != 0)
			return (-1);
	}
	if (data->info[i][6] < data->info[i][3]) {
		if (data->info[i][0] - 48 -
		(data->info[i][2] - data->info[i][5] +1) != 0)
			return (-1);
	}
	return (0);
}

int check_boat_error(void)
{
	int err;

	for (int i = 0; data->info[i] != NULL; i++) {
		if (data->info[i][5] == data->info[i][2]) {
			err = cas1(i);
		}
		else if (data->info[i][6] == data->info[i][3]) {
			err = cas2(i);
		}
		if (err == -1)
			return (-1);
	}
	return (0);
}
