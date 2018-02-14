/*
** EPITECH PROJECT, 2018
** navy
** File description:
** map_add_boat functions
*/

# include "navy.h"

char **map_add_cas1(char **map, int nb, int i)
{
	int a;
	int b;

	a = data->info[i][3] - 48 + 1;
	b = (data->info[i][2] - 64) * 2;
	if (data->info[i][3] > data->info[i][6]) {
		while (nb > 0) {
			map[a][b] = data->info[i][0];
			nb--;
			a -= 1;
		}
	} else if (data->info[i][3] < data->info[i][6]) {
		while (nb > 0) {
			map[a][b] = data->info[i][0];
			nb--;
			a += 1;
		}
	}
	return (map);
}

char **map_add_cas2(char **map, int nb, int i)
{
	int a;
	int b;

	a = data->info[i][3] - 48 + 1;
	b = (data->info[i][2] - 64) * 2;
	if (data->info[i][2] < data->info[i][5]) {
		while (nb > 0) {
			map[a][b] = data->info[i][0];
			nb--;
			b += 2;
		}
	} else if (data->info[i][2] < data->info[i][5]) {
		while (nb > 0) {
			map[a][b] = data->info[i][0];
			nb--;
			b -= 2;
		}
	}
	return (map);
}

char **map_add_boat(char **map)
{
	int nb;

	for (int i = 0; data->info[i] != NULL; i++) {
		nb = data->info[i][0] - 48;
		if (data->info[i][2] == data->info[i][5]) {
			map = map_add_cas1(map, nb, i);
		}
		else if (data->info[i][3] == data->info[i][6]) {
			map = map_add_cas2(map, nb, i);
		}
	}
	return (map);
}
