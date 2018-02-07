/*
** EPITECH PROJECT, 2018
** PSU_navy_2017
** File description:
** main function
*/

# include "navy.h"

static void display_help(void)
{
	my_putstr("USAGE:\n");
	my_putstr("\t./navy [pid] <pos>\n\n");
	my_putstr("DESCRIPTION:\n");
	my_putstr("\tpid\tpid of the first player (only 2nd player)\n");
	my_putstr("\tpos\tPositions of the ships.\n");
}

static int check_arguments(int ac, char **av)
{
	if (ac == 2 && my_strequ(av[1], "-h")) {
		display_help();
		return (0);
	}

	if (ac == 3) {
		if (!my_str_isnum(av[1])) {
			my_puterr("The pid must be a number.\n", false);
			my_puterr("Usage: ./navy [pid] <pos>\n", false);
			return (84);
		}
	} else if (ac < 2 || ac > 3) {
		my_puterr("Wrong argument amount.\n", false);
		my_puterr("Usage: ./navy [pid] <pos>\n", false);
		return (84);
	}

	return (1);
}

int main(int ac, char **av)
{
	int res 		= 0;
	data_t *data 	= NULL;

	if ((res = check_arguments(ac, av)) != 1)
		return (res);

	data = config_struct(ac, av);
	if (data == NULL) {
		my_puterr("Malloc failed. Aborded.\n", false);
		return (84);
	}

	navy(data);
	res = data->status;
	free(data);

	return (res);
}