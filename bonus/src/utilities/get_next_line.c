/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line c file
*/

#include "navy.h"

static int check_str(char *str, int n)
{
	int nb = 0;

	if (str == NULL)
		return (0);
	while (str[nb] != '\0') {
		if (str[nb] == '\n')
			if (n == 2)
				return (2);
		nb++;
	}
	if (n == 2)
		return (0);
	return (nb);
}

static char *get_rest(char *rest)
{
	char *str;
	int count = 0;

	if (rest == NULL) {
		return (NULL);
	}
	for (int i = 0; rest[i] != '\n' && rest[i] != '\0'; i++) {
		count++;
	}
	str = malloc(sizeof(char) * count + 1);
	if (str == NULL)
		return (NULL);
	for (int i = 0; i < count; i++) {
		str[i] = rest[i];
	}
	str[count] = '\0';
	return (str);
}

static char *get_new_rest(char *buffer)
{
	char *str;
	int len = check_str(buffer, 0);
	int nb = 0;
	int count = 0;

	for (int i = 0; buffer[i] != '\0'; i++) {
		if (buffer[i] == '\n') {
			nb = i + 1;
			str = malloc(sizeof(char) * len - nb + 1);
			if (str == NULL)
				return (NULL);
			for (int j = nb; buffer[j] != '\0'; j++) {
				str[count] = buffer[j];
				count++;
			}
			str[count] = '\0';
			return (str);
		}
	}
	return (NULL);
}

static char *get_the_line(char *line, char *buffer)
{
	int n = 0;
	int len = check_str(line, 0);
	char *str;

	if (line == NULL && buffer == NULL)
		return (NULL);
	for (int i = 0; buffer[i] != '\n' && buffer[i] != '\0'; i++)
		len++;
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	if (line != NULL)
		for (int i = 0 ; line[i] != '\0'; i++) {
			str[i] = line[i];
			n = i + 1;
		}
	free(line);
	for (int i = 0; i + n < len; i++)
		str[i + n] = buffer[i];
	str[len] = '\0';
	return (str);
}

char *get_next_line(int fd)
{
	static char *rest;
	char *line;
	char buffer[READ_SIZE + 1];
	int res = check_str(rest, 2);
	int f;

	if (res > 0) {
		line = get_rest(rest);
		rest = get_new_rest(rest);
		return (line);
	} else if (res == 0) {
		line = get_rest(rest);
		while (res == 0) {
			f = read(fd, buffer, READ_SIZE);
			buffer[f] = '\0';
			res = check_str(buffer, 2);
			if (f == 0 && res == 0 && buffer[0] == '\0') {
				free(rest);
				return (NULL);
			}
			line = get_the_line(line, buffer);
		}
		if (rest != NULL)
			free(rest);
		rest = get_new_rest(buffer);
	}
	return (line);
}
