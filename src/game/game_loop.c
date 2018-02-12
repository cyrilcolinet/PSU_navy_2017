/*
** EPITECH PROJECT, 2018
** player_turn
** File description:
** navy
*/

# include "navy.h"

void player_turn(void)
{
	int response;

	while (true && data->status != 84) {
		map_display();
		str = get_next_line;
		send_data(str);
		get_sended_response();
		pause();
		if (data->received) {
			check_player_hit_fail(str, data->data, data->enemy);
			data->received = false;
		}
		if (check_end_game(data->map) == 1) {
			my_putstr("I won\n");
			data->status = 0;
			break;
		}
		my_putstr("waiting for enemy's attack...\n");
		get_sended_data();
		pause();
		if (data->received) {
			response = check_enemy_hit_fail(data->data, data->map);
			data->received = false;
		}
		send_response(response);
		if (check_end_game(data->enemy) == 1) {
			my_putstr("Enemy won\n");
			data->status = 1;
			break;
		}
	}
}
