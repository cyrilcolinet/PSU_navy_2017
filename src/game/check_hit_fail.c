/*
** EPITECH PROJECT, 2018
** check_hit_fail
** File description:
** navy
*/

#include "navy.h"

void check_player_hit_fail(char *str, int data, char **map)
{
	int nb = get_case_number(str);
	int x = nb / 8;
	int y = nb % 8;

	if (y == 0) {
		x -= 1;
		y = 8;
	}
	my_putstr(str);
	if (data == 1) {
		my_putstr(": hit\n");
		map[x + 1][y + 1] = 'x';
	} else if (data == 2) {
		my_putstr(": missed\n");
		map[x + 1][y + 1] = 'o';
	}
}

int check_enemy_hit_fail(int nb, char **map)
{
	int x = nb / 8;
	int y = nb % 8;

	if (y == 0) {
		x -= 1;
		y = 8;
	}
	if (map[x + 1][y + 1] <= '5' && map[x + 1][y + 1] >= '2') {
		my_putstr(y + 64);
		my_putstr(x + 48);
		my_putstr(": hit\n");
		map[x + 1][y + 1] = 'x';
		return (1);
	} else {
		my_putstr(y + 64);
		my_putstr(x + 48);
		my_putstr(": missed\n");
		map[x + 1][y + 1] = 'o';
		return (2);
	}
}
