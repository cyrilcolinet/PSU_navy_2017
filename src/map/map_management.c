/*
** EPITECH PROJECT, 2018
** 
** File description:
** map_utils functions
*/

# include "navy.h"

int map_management(data_t *data, char *file)
{
	int fdesc = open(file, O_RDONLY);
	char buff[33];
	int i = -1;
	int err = check_map_error(data);

	if (err == -1) {
		my_puterr("map invalid !!", false);
		return (84);
	}

	if (read(fdesc, buff, 32) < 0) {
		write(2, "Invalid read size.\n", 19);
		return (NULL);
	}

	if (my_strlen(buff) != 32 || my_countwords(buff, '\n') != 4)
		return (NULL);

	tmp = my_strtok(buff, '\n');

	while (tmp[++i] != NULL) {
		if (my_countwords(*tmp, ':') != 3)
			return (NULL);

		map = my_strtok(*tmp, ':');

		for (int i = 0; map[i]; i++)
			printf("%s\n", map[i]);
		printf("\n");
	}

	my_freetab(tmp);
	return (0);
}
