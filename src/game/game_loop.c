/*
** EPITECH PROJECT, 2018
** player_turn
** File description:
** navy
*/

# include "navy.h"

void player_two(char **input)
{

}

void player_one(char **input)
{
	map_display();
	get_input(input);
	send_data(*input);
	get_response();
	pause();

	if (data->received) {
		my_putstr(*input);
		my_putstr(": ");
		my_putstr(((data->data == 1) ? "hit" : "missed"));
		reset_receivement();
	}
}

void player_turn(void)
{
	char *input = NULL;
	int response;

	while (true && data->status != 84) {
		if (data->type == playerOne) {
			player_one(&input);
		} else {
			player_two(&input);
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
<<<<<<< HEAD

	free(input);
}
=======
}
>>>>>>> d2d3a6ee7bc2497fdcbb5b33b3005c12f81e7451
