/*
** EPITECH PROJECT, 2018
** 
** File description:
** map_utils functions
*/

# include "navy.h"

int map_management(data_t *data, char *file)
{
	int fd = open(file, O_RDONLY);
	char buff[32];
	int err;

	read(fd, buff, 31);
	buff[31] = '\0';
	err = check_map_error(data, buff);
	if (err == -1) {
		my_puterr("map invalid !!\n", false);
		return (84);
	}
	map_creation(data);
	return (0);
}
