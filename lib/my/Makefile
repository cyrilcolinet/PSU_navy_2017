##
## EPITECH PROJECT, 2017
## libmy
## File description:
## Makefile libmy
##

## Color variables

SUCCESS				= /bin/echo -e "\x1b[1m\x1b[33m\#\#\x1b[32m $1\x1b[0m"

## Compilation variables

.PHONY				: all, clean, fclean, re

NAME 				= libmy.a

SRCNAMES			= my_atoi.c 					\
					my_countwords.c 				\
					my_freetab.c 					\
					my_put_nbr.c 					\
					my_putchar.c 					\
					my_putstr.c 					\
					my_str_isnum.c 					\
					my_strcat.c 					\
					my_strcmp.c 					\
					my_strconfigure.c 				\
					my_strequ.c 					\
					my_strlen.c 					\
					my_strtok.c

SRC 				= $(addprefix src/, $(SRCNAMES))

CFLAGS 				= -Wall -Wextra -I./include

CC					= gcc

AR 					= ar rcs

CP 					= cp

RM 					= rm -f

INCLUDE 			= ./include

REMOTE_INCLUDE 		= ../../include/

INCLUDE_FILE		= my.h

LIB_OBJ 			= $(SRC:.c=.o)

all:				$(NAME)
					$(CP) $(NAME) ../$(NAME)
					$(CP) $(INCLUDE)/$(INCLUDE_FILE) $(REMOTE_INCLUDE)
					@$(call SUCCESS, "Header\(s\) and static library\(ies\) copied.")

$(NAME):			$(LIB_OBJ)
					$(AR) $(NAME) $(LIB_OBJ)
					@$(call SUCCESS, "Library successfully compiled.")

clean:
					$(RM) $(LIB_OBJ)

fclean: 			clean
					$(RM) ../$(NAME)
					$(RM) $(NAME)
					$(RM) $(REMOTE_INCLUDE)$(INCLUDE_FILE)
					@$(call SUCCESS, "Library fully cleaned.")

re: 				fclean all
