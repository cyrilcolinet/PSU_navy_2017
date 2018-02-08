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
	char **tmp = NULL;
	char buff[33];
	int fdesc = open(file, O_RDONLY);

	if (read(fdesc, buff, 32) < 0) {
		write(2, "Invalid read size.\n", 19);
		return (NULL);
	}

	if (my_strlen(buff) != 32 || my_countwords(buff, '\n') != 4)
		return (NULL);

	tmp = my_strtok(buff, '\n');

	while (*tmp != NULL) {
		if (my_countwords(*tmp, ':') != 3)
			return (NULL);

		map = my_strtok(*tmp, ':');

		for (int i = 0; map[i]; i++)
			printf("%s\n", map[i]);
		printf("\n");
		tmp++;
	}

	my_freetab(tmp);
	return (map);
}