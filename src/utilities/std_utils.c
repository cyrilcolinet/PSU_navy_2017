/*
** EPITECH PROJECT, 2018
** navy
** File description:
** std_utils functions
*/

# include "navy.h"

char *stdin_redirect(void)
{
	char *buff = malloc(sizeof(*buff * 4));
	int res = -1;

	if (buff == NULL) {
		write(2, "Malloc failed.\n", 15);
		data->status = 84;
		return (NULL);
	}

	res = read(0, buff, 3);

	if (res < 0 || my_strlen(buff) != 3) {
		my_putstr("wrong position\n");
		return (NULL);
	}

	return (buff);
}

void get_input(char **input)
{
	my_putstr("attack: ");
	*input = stdin_redirect();
}