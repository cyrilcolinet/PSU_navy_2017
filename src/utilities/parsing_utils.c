/*
** EPITECH PROJECT, 2018
** navy
** File description:
** parsing_utils functions
*/

# include "navy.h"

int get_case_number(char *column)
{
	int value = (my_atoi(&column[1]) - 1) * 8;

	value += (column[0] - 16) - 48;
	return (value + 2);
}