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
# include <signal.h>
# include <time.h>
# include "my.h"

typedef enum pType {
	playerOne, playerTwo
} 	pl_e;

typedef struct p1 {
	int 	p2_pid;
	char 	**map;
	char	**enemy;
} 	p1_t;

typedef struct p2 {
	int 	p1_pid;
	char 	**map;
	char	**enemy;
} 	p2_t;

typedef struct datas {
	int 	status;
	pl_e 	type;
	int 	received;
	bool 	connected;
	int 	pid;
	char	**info;
	p1_t 	*p1;
	p2_t 	*p2;
} 	data_t;

typedef struct sigaction sigact_t;

data_t *data;

// navy.c
int 		navy(int ac, char **av);

// connector/connector.c
int 		get_receiver_pid(void);
bool		send_data(char *column);
int 		configure_sig(int sig, void *action);
bool 		connector(void);

// connector/signals.c
void 		sig_get_sender(int sig, siginfo_t *si, void *ptr);
void 		sigusr_receiver(int sig, siginfo_t *si, void *ptr);

// utilities/struct_utils.c
void 		free_p1(p1_t *playerOne);
void 		free_p2(p2_t *playerTwo);
bool 		config_struct(int ac, char **av);
p1_t 		*config_struct_p1(char **av);
p2_t 		*config_struct_p2(char **av);

// utilities/map_utils.c
int			map_management(char *file);
int			check_map_error(char *buff);
int			check_boat_error(void);
void		map_add_boat(void);
void		map_creation(void);
void		map_affichage(void);

// utilities.parsing_utils.c
int 		get_case_number(char *column);

# endif
