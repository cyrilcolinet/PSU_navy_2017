/*
** EPITECH PROJECT, 2018
** map_creation
** File description:
** navy
*/

#include "navy.h"

static void map_remplissage(char **map)
{
	int nb = 49;
	int alpha = 65;

	for (int i = 0; i < 10; i++) {
		map[i] = malloc(sizeof(char) * 18);
		map[i][17] = '\0';
		map[i][1] = '|';
	}
	for (int i = 0; i < 17 ; i++)
		map[1][i] = '-';
	map[0][0] = ' ';
	map[1][1] = '+';
	for (int i = 2; i < 17; i ++) {
		if (i % 2 == 0) {
			map[0][i] = alpha;
			alpha++;
		} else
			map[0][i] = ' ';
	}
	for (int i = 2; i < 10; i++) {
		map[i][0] = nb;
		nb++;
	}
	for (int i = 2; i < 10; i++)
		for (int j = 2; j < 17; j++)
			map[i][j] = '.';


	for (int i = 0; map[i] != NULL; i++)
		printf("%s\n", map[i]);
}

void map_creation(void)
{
	if (data->type == playerOne) {
		data->p1->map = malloc(sizeof(char*) * 11);
		data->p1->map[10] = NULL;
		map_remplissage(data->p1->map);
	} else if (data->type == playerOne) {
		data->p2->map = malloc(sizeof(char*) * 11);
		data->p2->map[10] = NULL;
		map_remplissage(data->p2->map);
	}
}
