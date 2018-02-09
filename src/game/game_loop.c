/*
** EPITECH PROJECT, 2018
** player_turn
** File description:
** navy
*/

#include "navy.h"

void player_turn(void)
{
	while (data->winner == 0 || data->status == 0) {
		//map_affichage();
		pause();

		if (data->received)
			break;
	}
}
