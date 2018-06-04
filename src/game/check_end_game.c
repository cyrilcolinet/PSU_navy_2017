/*
** EPITECH PROJECT, 2018
** check_end_game
** File description:
** navy
*/

#include "navy.h"

int check_end_game(char **map)
{
	int count = 0;
	int i = 0;
	int j = 0;

	for (i = 2; map[i] != NULL; i++) {
		for (j = 2; map[i][j] != '\0'; j++) {
			if (map[i][j] == 'x')
				count++;
		}
	}
	if (count == 14)
		return (1);
	return (0);
}
