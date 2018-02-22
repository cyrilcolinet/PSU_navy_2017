/*
** EPITECH PROJECT, 2018
** navy
** File description:
** navy_main functions
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

static int check_file(char *s)
{
	int fd;
	int rd;
	char buffer[20];

	if (my_strequ(s, "-h")) {
		display_help();
		return (0);
	}
	fd = open(s, O_RDONLY);
	if (fd < 0) {
		write(2, s, my_strlen(s));
		write(2, " : invalid file.\n", 17);
		return (84);
	}
	rd = read(fd, buffer, 20);
	if (rd <= 0) {
		write(2, "The file is empty or the read failed.\n", 38);
		return (84);
	}
	return (-1);
}

static int check_arguments(int ac, char **av)
{
	int err = -1;

	if (ac == 2) {
		err = check_file(av[1]);
		if (err != -1)
			return (err);
	} else if (ac == 3){
		if (!my_str_isnum(av[1])) {
			write(2, "The pid must be a number.\n", 26);
			write(2, "Usage: ./navy [pid] <pos>\n", 26);
			return (84);
		}
		err = check_file(av[2]);
		if (err != -1)
			return (err);
	}
	return (1);
}

int navy_main(int ac, char **av)
{
	int res	= 0;

	if (ac < 2 || ac > 3) {
		write(2, "Wrong argument amount.\n", 23);
		write(2, "Usage: ./navy [pid] <pos>\n", 26);
		return (84);
	} else if ((res = check_arguments(ac, av)) != 1)
		return (res);
	res = navy(ac, av);
	return (res);
}