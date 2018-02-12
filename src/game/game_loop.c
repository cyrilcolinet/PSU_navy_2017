/*
** EPITECH PROJECT, 2018
** player_turn
** File description:
** navy
*/

#include "navy.h"

void player_turn(void)
{
	while (1) {
		if (check_end_game(data->map) == 1) {
			my_putstr("Enemy won\n");
			break;
		}
		get_sended_data();
		pause();

		if (data->received) {
			data->received = false;
			map_display();
		}
		if (check_end_game(data->enemy) == 1) {
			my_putstr("I won\n");
			break;
		}
	}
}
