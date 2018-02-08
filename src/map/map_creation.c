/*
** EPITECH PROJECT, 2018
** map_creation
** File description:
** navy
*/

#include "navy.h"

static void map_renseignement(char **map)
{
	for (int i = 0; map[i] != NULL; i++) {
		map[i] = malloc(sizeof(char) * 18);
		map[i] = '\0';
	}
}

void map_creation(data_t *data)
{
	if (data->type == playerOne) {
		data->p1->map = malloc(sizeof(char*) * 11);
		data->p1->map[10];
		map_renseignement(data->p1->map);
	} else if (data->type == playerOne) {
		data->p2->map = malloc(sizeof(char*) * 11);
		data->p2->map[10];
		map_renseignement(data->p2->map);
	}
}
