/*
** EPITECH PROJECT, 2018
** player_turn
** File description:
** navy
*/

# include "navy.h"

void waiting_enemy(void)
{
	int resp = 0;

	my_putstr("waiting for enemy's attack...\n");
	get_sended_data();
	resp = check_enemy_hit_fail(data->data, data->map);
	reset_receivement();
	send_response(resp);
}

void player_one(void)
{
	char *s;

	while (data->status != 84) {
		map_display();
		s = get_input();
		send_data(s);
		get_response();
		check_player_hit_fail(s, data->data, data->enemy);
		reset_receivement();
		if (check_end_game(data->enemy)) {
			data->status = 0;
			break;
		}
		waiting_enemy();
		if (check_end_game(data->map)) {
			data->status = 1;
			break;
		}
	}
}

void player_two(void)
{
	char *s;

	while (data->status != 84) {
		map_display();
		waiting_enemy();
		if (check_end_game(data->map)) {
			data->status = 1;
			break;
		}
		s = get_input();
		send_data(s);
		get_response();
		check_player_hit_fail(s, data->data, data->enemy);
		reset_receivement();
		if (check_end_game(data->enemy)) {
			data->status = 0;
			break;
		}
	}
}

void player_turn(void)
{
	if (data->type == playerOne) {
		player_one();
	} else {
		player_two();
	}
	map_display();
	if (data->status == 0) {
		my_putstr("I won\n");
	} else if (data->status == 1) {
		my_putstr("Enemy won\n");
	}
}
