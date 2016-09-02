##
## Makefile for  in /home/rusign/rendu/UNIX/PSU_2015_lemipc
##
## Made by nicolas rusig
## Login   <rusign@epitech.net>
##
## Started on  Tue Mar 15 09:38:39 2016 nicolas rusig
## Last update Sun Mar 27 00:07:45 2016 nicolas rusig
##

NAME	= lemipc

SRC	= src/main.c		\
	  src/error.c		\
	  src/create.c		\
	  src/move.c		\
	  src/did_i_died.c	\
	  src/comunicate.c	\
	  src/strategies.c	\
	  src/game.c

OBJ	= $(SRC:.c=.o)

INC_DIR = include

GCC	= cc

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -I$(INC_DIR)


all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
