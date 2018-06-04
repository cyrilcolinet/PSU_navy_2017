/*
** EPITECH PROJECT, 2018
** map_affichage
** File description:
** navy
*/

# include "navy.h"

void map_display(void)
{
	int i = 0;

	if (data->map == NULL)
		return;
	else {
		my_putstr("my positions:\n");
		for (i = 0; data->map[i] != NULL; i++) {
			my_putstr(data->map[i]);
			my_putstr("\n");
		}
		my_putstr("\n");
		my_putstr("enemy's positions:\n");
			for (i = 0; data->enemy[i] != NULL; i++) {
		my_putstr(data->enemy[i]);
				my_putstr("\n");
		}
		my_putstr("\n");
	}
}
