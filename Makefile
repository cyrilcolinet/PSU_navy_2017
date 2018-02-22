##
## EPITECH PROJECT, 2017
## navy_2017
## File description:
## Makefile with build project rule and units tests
##

## Global variables

SUCCESS				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"

INFO				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[34m $1\x1b[0m"

HOST				= $(shell printenv HOME)

DEBUG				= -g3

COMPILE_LIBRARY		= $(shell [ -e $(LIBDIR) ] && echo -e "ok" || echo -e "no")

## Compilation variables

NAME 				= navy

UNIT 				= units

SRCDIR 				= src/

TESTSDIR			= tests/

SRCNAMES			= main.c			\
				navy.c				\
				navy_main.c 			\
				utilities/data_utils.c 		\
				utilities/struct_utils.c	\
				utilities/std_utils.c 		\
				utilities/get_next_line.c	\
				utilities/parsing_utils.c	\
				connector/connector.c		\
				connector/signals.c		\
				connector/handlers.c		\
				map/error/check_map_error.c	\
				map/error/check_boat_error.c	\
				map/map_creation.c		\
				map/map_management.c		\
				map/map_add_boat.c		\
				map/map_display.c		\
				game/game_loop.c		\
				game/check_end_game.c		\
				game/check_hit_fail.c

SRC 				= $(addprefix $(SRCDIR), $(SRCNAMES))

SRCTESTS			= src/navy.c				\
				src/navy_main.c 			\
				src/utilities/data_utils.c 		\
				src/utilities/struct_utils.c	\
				src/utilities/std_utils.c 		\
				src/utilities/get_next_line.c	\
				src/utilities/parsing_utils.c	\
				src/connector/connector.c		\
				src/connector/signals.c		\
				src/connector/handlers.c		\
				src/map/error/check_map_error.c	\
				src/map/error/check_boat_error.c	\
				src/map/map_creation.c		\
				src/map/map_management.c		\
				src/map/map_add_boat.c		\
				src/map/map_display.c		\
				src/game/game_loop.c		\
				src/game/check_end_game.c		\
				src/game/check_hit_fail.c 		\
				tests/$(NAME)_wrong_file_tests.c

INC 				= include

BUILDDIR 			= build/

BUILDTESTDIR 			= build_tests/

BUILDSUBDIR 			= $(shell find $(SRCDIR) -mindepth 1 -type d -printf '%p\n' | sed -e 's/^src\///')

BUILDTESTSUBDIR 		= $(shell find $(SRCDIR) -mindepth 1 -type d -printf '%p\n' | sed -e 's/^tests\///')

BUILDOBJS 			= $(addprefix $(BUILDDIR), $(SRCNAMES:.c=.o)) ## Check

BUILDTESTOBJS 			= $(SRCTESTS:.c=.o)

LIBDIR 				= lib/

LIBMY 				= $(LIBDIR)libmy.a

CC 				= gcc

CFLAGS 				= -Wall -Wextra -I$(INC) $(DEBUG)

LFLAGS				= $(if $(filter ok, $(COMPILE_LIBRARY)), -L$(LIBDIR) -lmy, )

UNITS_LIBRARY_FLAG		= $(LFLAGS) -lcriterion

OBJ 				= $($SRC:.c=.o)

## Rules

all: 				$(BUILDDIR) $(LIBMY) $(NAME)
				@$(call SUCCESS, "Project successfully compiled.")

tests_run: 			$(BUILDTESTDIR) $(LIBMY) $(UNIT)
				@$(call SUCCESS, "Unitary tests successfully compiled.")
				@clear
				@echo -e "\n"
				@$(call SUCCESS, "Execution of criterion tests...")
				@./$(UNIT)
				@$(call SUCCESS, "All tests passed !")

clean:
				rm -rf $(BUILDDIR)
				rm -rf $(BUILDTESTDIR)
				find -name '*.gc*' -delete -or -name 'vgcore.*' -delete
				$(if $(filter ok, $(COMPILE_LIBRARY)), make clean -C $(LIBDIR), @$(call INFO, "No lib needed for this project."))
				@$(call SUCCESS, "Project fully cleaned.")

fclean: 			clean
				rm -rf $(NAME)
				rm -rf $(UNITS)
				$(if $(filter ok, $(COMPILE_LIBRARY)), make fclean -C $(LIBDIR), @$(call INFO, "No lib needed for this project."))

re: 				fclean all

bonus:				clean
				make -C ./bonus

$(BUILDDIR):
				mkdir -p $(BUILDDIR)
				$(foreach subdir, $(BUILDSUBDIR), $(shell mkdir -p $(BUILDDIR)$(subdir)))

$(BUILDTESTDIR):
				mkdir -p {$(BUILDTESTDIR)src,$(BUILDTESTDIR)tests}
				$(foreach subdir, $(BUILDSUBDIR), $(shell mkdir -p $(BUILDTESTDIR)src/$(subdir)))
				$(foreach subdir, $(BUILDTESTSUBDIR), $(shell mkdir -p $(BUILDTESTDIR)tests/$(subdir)))

$(BUILDDIR)%.o:			$(SRCDIR)%.c
				$(CC) $(CFLAGS) --coverage   -c -o $@ $< -lgcov

$(BUILDTESTDIR)src/%.o:		$(SRCDIR)%.c
				$(CC) $(CFLAGS) --coverage   c -o $@ $< -lgcov

				$(CC) $(CFLAGS) -o $(NAME) $(BUILDOBJS) $(LFLAGS)
$(BUILDTESTDIR)tests/%.o:	$(TESTSDIR)%.c
				$(CC) $(CFLAGS) --coverage   -c -o $@ $< -lgcov

$(NAME): 			$(BUILDOBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(BUILDOBJS) $(LFLAGS)
				@$(call SUCCESS, "All objects files successfully regrouped in ./$(NAME) binary file.")

$(LIBMY):
				$(if $(filter ok, $(COMPILE_LIBRARY)), make -C $(LIBDIR), @$(call INFO, "No lib needed for this project."))

$(UNIT): 			$(BUILDTESTOBJS)
				$(CC) $(CFLAGS) -o units $(BUILDTESTOBJS) $(UNITS_LIBRARY_FLAG)
				@$(call SUCCESS, "All tests objects files successfully regrouped in ./$(NAME) binary file.")

# Just in case those files exist in the root dir
.PHONY				: all fclean clean re tests_run
