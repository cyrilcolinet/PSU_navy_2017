/*
** EPITECH PROJECT, 2018
** map_creation
** File description:
** navy
*/

#include "navy.h"

static char ** map_alpha_nb(char **map)
{
	int nb = 49;
	int alpha = 65;

	for (int i = 2; i < 17; i++) {
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
	return (map);
}

static char ** map_empty_board(char **map)
{
	for (int i = 2; i < 10; i++)
		for (int j = 2; j < 17; j++) {
			if (j % 2 == 0) {
				map[i][j] = '.';
			} else
				map[i][j] = ' ';
		}
	return (map);
}

static char ** map_remplissage(char **map)
{
	for (int i = 0; i < 10; i++) {
		map[i] = malloc(sizeof(char) * 18);
		map[i][17] = '\0';
		map[i][1] = '|';
	}
	for (int i = 0; i < 17 ; i++)
		map[1][i] = '-';
	map[0][0] = ' ';
	map[1][1] = '+';
	map_alpha_nb(map);
	map_empty_board(map);
	return (map);
}

void map_creation(void)
{
	if (data->type == playerOne) {
		data->p1->map = malloc(sizeof(char *) * 11);
		data->p1->map[10] = NULL;
		data->p1->map = map_remplissage(data->p1->map);
		data->p1->enemy = malloc(sizeof(char *) * 11);
		data->p1->enemy[10] = NULL;
		data->p1->enemy = map_remplissage(data->p1->enemy);
	} else if (data->type == playerTwo) {
		data->p2->map = malloc(sizeof(char *) * 11);
		data->p2->map[10] = NULL;
		data->p2->map = map_remplissage(data->p2->map);
		data->p2->enemy = malloc(sizeof(char *) * 11);
		data->p2->enemy[10] = NULL;
		data->p2->enemy = map_remplissage(data->p2->enemy);
	}
	map_affichage();
}
