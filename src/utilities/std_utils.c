/*
** EPITECH PROJECT, 2018
** navy
** File description:
** std_utils functions
*/

# include "navy.h"

char *stdin_redirect(void)
{
	char *str = get_next_line(0);
	int len;

	if (str == NULL)
		return (NULL);
	len = my_strlen(str);
	if (len != 2) {
		my_putstr("wrong position\n");
		return (NULL);
	}
	if ((str[0] < 'A' && str[0] > 'H') ||
	(str[1] < '1' && str[1] > '8')) {
		my_putstr("wrong position\n");
		return (NULL);
	}
	return (str);
}

void get_input(char **input)
{
	while (1) {
		my_putstr("attack: ");
		*input = stdin_redirect();
		if (*input != NULL)
			break;
	}
}
