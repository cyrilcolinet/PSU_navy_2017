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
	if ((str[0] < 'A' || str[0] > 'H') ||
	(str[1] < '1' || str[1] > '8')) {
		my_putstr("wrong position\n");
		return (NULL);
	}
	return (str);
}

char *get_input(void)
{
	int a = 1;
	char *s;

	while (a == 1) {
		my_putstr("attack: ");
		s = stdin_redirect();
		if (s != NULL) {
			a = 2;
			return (s);
		}
		if (a == 1)
			free(s);
	}
	return (NULL);
}
