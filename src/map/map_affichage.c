/*
** EPITECH PROJECT, 2018
** map_affichage
** File description:
** navy
*/

#include "navy.h"

void map_affichage(void)
{
	/*if (data->type == playerOne) {
		if (data->p1->map == NULL)
			return;
		else {
			my_putstr("my positions:\n");
			for (int i = 0; data->p1->map[i] != NULL; i++) {
				my_putstr(data->p1->map[i]);
				my_putstr("\n");
			}
			my_putstr("\n");
			my_putstr("enemy's positions:\n");
			for (int i = 0; data->p1->enemy[i] != NULL; i++) {
				my_putstr(data->p1->enemy[i]);
				my_putstr("\n");
			}
			my_putstr("\n");
		}
	}
	if (data->type == playerTwo) {
		if (data->p2->map == NULL)
			return;
		else {
			my_putstr("my positions:\n");
			for (int i = 0; data->p2->map[i] != NULL; i++) {
				my_putstr(data->p2->map[i]);
				my_putstr("\n");
			}
			my_putstr("\n");
			my_putstr("enemy's positions:\n");
			for (int i = 0; data->p2->enemy[i] != NULL; i++) {
				my_putstr(data->p2->enemy[i]);
				my_putstr("\n");
			}
			my_putstr("\n");
		}
	}*/

	if (data->map == NULL)
		return;
	else {
		my_putstr("my positions:\n");
		for (int i = 0; data->map[i] != NULL; i++) {
			my_putstr(data->map[i]);
			my_putstr("\n");
		}
		my_putstr("\n");
		my_putstr("enemy's positions:\n");
			for (int i = 0; data->enemy[i] != NULL; i++) {
		my_putstr(data->enemy[i]);
				my_putstr("\n");
		}
		my_putstr("\n");
	}
}
