/*
** EPITECH PROJECT, 2018
** navy_2017
** File description:
** navy functions (header file)
*/

# ifndef NAVY_H
# define NAVY_H

# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include "my.h"

typedef enum pType {
	playerOne, playerTwo
} pl_e;

typedef struct p1 {
	int 	p2_pid;
	char 	**map;
} p1_t;

typedef struct p2 {
	int 	p1_pid;
	char 	**map;
} p2_t;

typedef struct datas {
	int 	status;
	pl_e 	type;
	bool 	connected;
	int 	pid;
	char	**info;
	p1_t 	*p1;
	p2_t 	*p2;
} data_t;

typedef struct sigaction siga_t;

// navy.c
int 		navy(int ac, char **av);

// connector/connector.c
bool 		connector(data_t *data);

// utilities/struct_utils.c
void 		free_p1(p1_t *playerOne);
void 		free_p2(p2_t *playerTwo);
data_t 		*config_struct(int ac, char **av);
p1_t 		*config_struct_p1(data_t *data, char **av);
p2_t 		*config_struct_p2(data_t *data, char **av);

// utilities/map_utils.c
int		map_management(data_t *data, char *file);
int		check_map_error(data_t *data, char *buff);
void		map_creation(data_t *data);

# endif
