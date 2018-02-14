/*
** EPITECH PROJECT, 2018
** navy
** File description:
** check_map_error functions
*/

# include "navy.h"

int check_line(char *str)
{
	if (str[3] < '1' || str[3] > '8')
		return (-1);
	if (str[6] < '1' || str[6] > '8')
		return (-1);
	return (0);
}

int check_column(char *str)
{
	if (str[2] < 'A' || str[2] > 'H')
		return (-1);
	if (str[5] < 'A' || str[5] > 'H')
		return (-1);
	return (0);
}

int check_info(char *str)
{
	int err;

	err = check_line(str);
	if (err == -1)
		return (-1);
	err = check_column(str);
	if (err == -1)
		return (-1);
	return (0);
}

int check_boat(void)
{
	for (int i = 0; data->info[i] != NULL; i++) {
		if (data->info[i][0] < '2' ||
		data->info[i][0] > '5') {
			my_puterr("invalid boats\n", false);
			return (-1);
		}
	}
	if (data->info[0][0] != data->info[1][0]
	&& data->info[0][0] != data->info[2][0]
	&& data->info[0][0] != data->info[3][0]
	&& data->info[1][0] != data->info[2][0]
	&& data->info[1][0] != data->info[3][0]
	&& data->info[2][0] != data->info[3][0]) {
		return (0);
	}
	my_puterr("You need 4 different boats !!\n", false);
	return (-1);
}

int check_map_error(char *buff)
{
	int err;

	if (my_strlen(buff) < 31)
		return (-1);
	data->info = my_strtok(buff, '\n');
	err = check_boat();
	if (err == -1)
		return (-1);
	for (int i = 0; data->info[i] != NULL; i++) {
		err = check_info(data->info[i]);
		if (err == -1)
			return (-1);
	}
	err = check_boat_error();
	if (err == -1)
		return (-1);
	return (0);
}
