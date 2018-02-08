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

	for (int i = 0; map[i] != NULL; i++) {
		map[i] = malloc(sizeof(char) * 18);
		map[i][17] = '\0';
		map[i][1] = '|';
	}
	for (int i = 0; map[1][i] != '\0'; i++)
		map[1][i] = '-';
	map[0][0] = ' ';
	map[1][1] = '+';
	for (int i = 2; map[0][i] != '\0'; i++) {
		map[0][i] = alpha;
		alpha++;
	}
	for (int i = 2; map[i] != NULL; i++) {
		map[i][0] = nb;
		nb++;
	}
	for (int i = 2; map[i] != NULL; i++)
		for (int j = 2; map[i][j] != '\0'; j++)
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
