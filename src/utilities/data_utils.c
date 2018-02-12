/*
** EPITECH PROJECT, 2018
** navy
** File description:
** data_utils functions
*/

# include "navy.h"

void treat_received_response(char *input)
{
	if (data->received) {
		check_player_hit_fail(input, data->data, data->enemy);
		reset_receivement();
	}
}

void treat_received_data(char *input, int *resp)
{
	if (data->received) {
		*resp = check_enemy_hit_fail(data->data, data->map);
		reset_receivement();
	}
}