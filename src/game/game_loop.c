/*
** EPITECH PROJECT, 2018
** player_turn
** File description:
** navy
*/

# include "navy.h"

void waiting_enemy(void)
{
	my_putstr("waiting for enemy's attack...\n");
	get_sended_data();
	pause();
}

void player_two(char **input, bool *finished)
{
	map_display();
	waiting_enemy();
	send_response(treat_received_data());
	if (check_end_game(data->map)) {
		data->status = 1;
		*finished = true;
		return;
	}

	get_input(input);
	send_data(*input);
	get_response();
	pause();
	treat_received_response(*input);
	if (check_end_game(data->map)) {
		data->status = 0;
		*finished = true;
		return;
	}
}

void player_one(char **input, bool *finished)
{
	map_display();
	get_input(input);
	send_data(*input);
	get_response();
	pause();
	treat_received_response(*input);
	if (check_end_game(data->map)) {
		data->status = 0;
		*finished = true;
		return;
	}

	waiting_enemy();
	send_response(treat_received_data());
	if (check_end_game(data->map)) {
		data->status = 1;
		*finished = true;
		return;
	}
}

void player_turn(void)
{
	char *input = NULL;
	bool finished = false;

	while (true && data->status != 84 && !finished) {
		if (data->type == playerOne) {
			player_one(&input, &finished);
		} else {
			player_two(&input, &finished);
		}
/*
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
*/
	}

	if (data->status == 0) {
		my_putstr("I won\n");
	} else if (data->status == 1) {
		my_putstr("Enemy won\n");
	}

	//free(input);
}