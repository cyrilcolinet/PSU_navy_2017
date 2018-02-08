/*
** EPITECH PROJECT, 2018
** 
** File description:
** map_utils functions
*/

# include "navy.h"

char **get_map(char *file)
{
	char **map = NULL;
	char buff[33];
	int fdesc = open(file, O_RDONLY); // 32

	while (read(fdesc, buff, 32) != -1) {
		printf("%s\n", buff);
	}

	return (map);
}