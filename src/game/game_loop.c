/*
** EPITECH PROJECT, 2018
** player_turn
** File description:
** navy
*/

# include "navy.h"

static void waiting_enemy(void)
{
	my_putstr("waiting for enemy's attack...\n");
	get_sended_data();
}

static void player_one(bool *finished)
{
	char *s;
	int resp = 0;
	
	while (true) {
		map_display();
		s = get_input();
		send_data(s);
		get_response();
		check_player_hit_fail(s, data->data, data->enemy);
		reset_receivement();

		if (check_end_game(data->enemy)) {
			data->status = 0;
			*finished = true;
			break;
		}

		waiting_enemy();
		resp = check_enemy_hit_fail(data->data, data->map);
		send_response(resp);
		reset_receivement();
		if (check_end_game(data->map)) {
			data->status = 1;
			*finished = true;
			return;
		}
	}
}

static void player_two(bool *finished)
{
	char *s;
	int resp = 0;

	while (true) {
		map_display();
		waiting_enemy();
		resp = check_enemy_hit_fail(data->data, data->map);
		send_response(resp);
		reset_receivement();

		if (check_end_game(data->map)) {
			data->status = 1;
			*finished = true;
			break;
		}

		s = get_input();
		send_data(s);
		get_response();

		check_player_hit_fail(s, data->data, data->enemy);
		reset_receivement();

		if (check_end_game(data->enemy)) {
			data->status = 0;
			*finished = true;
			return;
		}
	}
}

void player_turn(void)
{
	bool finished = false;

	if (data->type == playerOne) {
		player_one(&finished);
	} else {
		player_two(&finished);
	}
	map_display();
	if (data->status == 0) {
		my_putstr("I won\n");
	} else if (data->status == 1) {
		my_putstr("Enemy won\n");
	}
}
