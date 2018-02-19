##
## EPITECH PROJECT, 2018
## navy (bonus)
## File description:
## Makefile for bonus projects
##

## Global variables

SUCCESS				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"

INFO				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[34m $1\x1b[0m"

HOST				= $(shell printenv HOME)

DEBUG				= -g3

COMPILE_LIBRARY		= $(shell [ -e $(LIBDIR) ] && echo -e "ok" || echo -e "no")

## Compilation variables

NAME 				= navy

SRC_FILES			= main.c					\
					navy.c 						\
					navy_main.c 				\
					utilities/data_utils.c 		\
					utilities/struct_utils.c	\
					utilities/std_utils.c 		\
					utilities/get_next_line.c	\
					utilities/parsing_utils.c	\
					connector/connector.c		\
					connector/signals.c			\
					connector/handlers.c		\
					map/error/check_map_error.c	\
					map/error/check_boat_error.c\
					map/map_creation.c			\
					map/map_management.c		\
					map/map_add_boat.c			\
					map/map_display.c			\
					game/game_loop.c			\
					game/check_end_game.c		\
					game/check_hit_fail.c

SRC 				= $(addprefix src/, $(SRC_FILES))

RM 					= rm -rf

CC 					= gcc

CFLAGS 				= -Wall -Wextra -I./include

OBJ 				= $(SRC:.c=.o)

## Rules

all: 				lib $(NAME)

lib:
					make -C ./lib/

$(NAME):			$(OBJ)
					$(CC) $(CFLAGS) -levent -L./lib -lmy -lredis $(OBJ) ./lib/my/src/*.o -o $(NAME)

clean:
					$(RM) $(OBJ)
					find -name '*.gc*' -delete -or -name 'vgcore.*' -delete
					make clean -C ./lib/

fclean: 			clean
					$(RM) $(NAME)
					make fclean -C ./lib/

re: 				fclean all

# Just in case those files exist in the root dir
.PHONY				: all fclean clean re lib