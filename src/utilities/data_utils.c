/*
** EPITECH PROJECT, 2018
** navy
** File description:
** data_utils functions
*/

# include "navy.h"

void treat_received_response(char *input)
{
	check_player_hit_fail(input, data->data, data->enemy);
	reset_receivement();
}

int treat_received_data(void)
{
	int resp = check_enemy_hit_fail(data->data, data->map);

	reset_receivement();
	return (resp);
}