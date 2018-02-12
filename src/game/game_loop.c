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
		map_display();
		if (check_end_game(data->map) == 1) {
			my_putstr("Enemy won\n");
			data->status = 1;
			break;
		}
		get_sended_data();
		pause();
		if (data->received) {
			check_hit_fail(data->data, data->map);
			data->received = false;
		}
		if (check_end_game(data->enemy) == 1) {
			my_putstr("I won\n");
			data->status = 0;
			break;
		}
	}
}
