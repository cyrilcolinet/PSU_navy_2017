/*
** EPITECH PROJECT, 2018
** navy_2017
** File description:
** navy functions
*/

# include "navy.h"

void navy(data_t *data)
{
	my_putstr("my_pid: ");
	my_put_nbr(data->pid);
	my_putchar('\n');
	free_p1(data->p1);
	free_p2(data->p2);
}
