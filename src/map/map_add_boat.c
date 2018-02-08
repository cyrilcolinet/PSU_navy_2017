/*
** EPITECH PROJECT, 2018
** map_add_boat
** File description:
** navy
*/

#include "navy.h"

char ** map_add_boat(char **map)
{
	int nb;

	map_affichage();
	for (int i = 0; data->info[i] != NULL; i++) {
		nb = data->info[i][0] - 48;
		if (data->info[i][2] == data->info[i][5]) {
			while (nb > 1) {
				data->map[i]
				nb--;
			}
		}
		else if (data->info[i][3] == data->info[i][6]) {
			while (nb > 1) {
				nb--;
			}
		}
	}
	return (map);
}
