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

typedef struct datas {
	int 	status;
	pl_e 	type;
	int 	data;
	bool 	received;
	bool 	connected;
	int 	pid;
	int 	pid2;
	char	**info;
	char 	**map;
	char 	**enemy;
} 	data_t;

typedef struct sigaction sigact_t;

data_t 		*data;

// main.c
int 		navy_main(int ac, char **av);

// navy.c
int 		game_manager(void);
int 		navy(int ac, char **av);

// connector/connector.c
void 		reset_receivement(void);
bool 		send_signal(int pid, int sig);
bool 		send_response(int resp);
bool		send_data(char *column);
bool 		connector(void);

// connector/handlers.c
void 		pid_handler(int sig, siginfo_t *si, void *ptr);
void 		data_handler(int sig, siginfo_t *si, void *ptr);

// connector/signals.c
void 		get_player_pid(void);
void 		get_sended_data(void);
void 		get_response(void);

// game/game_loop.c
void 		player_turn(void);

// game/check_game_loop.c
int		check_end_game(char **map);

// game/check_hit_fail.c
void		check_player_hit_fail(char *str, int data, char **map);
int		check_enemy_hit_fail(int data, char **map);

// map/error/check_boat_error.c
int 		cas1(int i);
int 		cas2(int i);
int 		check_boat_error(void);

// map/error/check_map_error.c
int 		check_line(char *str);
int			check_column(char *str);
int 		check_info(char *str);
int			check_boat(void);
int 		check_map_error(char *buff);

// map/map_add_boat.c
char 		**map_add_cas1(char **map, int nb, int i);
char 		**map_add_cas2(char **map, int nb, int i);
char 		**map_add_boat(char **map);

// map/map_creation.c
char 		**map_alpha_nb(char **map);
char 		**map_empty_board(char **map);
char 		**map_fill(char **map);
void 		map_creation(void);

// map/map_display.c
void 		map_display(void);

// map/map_management.c
int 		map_management(char *file);

// utilities/data_utils.c
void 		treat_received_response(char *input);
void 		treat_received_data(char *input, int *resp);

// utilities.parsing_utils.c
int 		get_case_number(char *column);

// utilities/std_utils.c
char 		*stdin_redirect(void);
void 		get_input(char **input);

// utilities/struct_utils.c
void 		free_struct(void);
bool 		config_struct(int ac, char **av);

# endif
