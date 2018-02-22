/*
** EPITECH PROJECT, 2018
** map_management
** File description:
** navy
*/

# include "navy.h"

int map_management(char *file)
{
	int fd = open(file, O_RDONLY);
	char buff[32];
	int err;

	read(fd, buff, 31);
	buff[31] = '\0';
	err = check_map_error(buff);
	if (err == -1) {
		write(2, "map invalid !!\n", 15);
		return (84);
	}
	return (0);
}
