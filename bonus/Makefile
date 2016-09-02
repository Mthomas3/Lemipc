##
## Makefile for  in /home/rusign/rendu/UNIX/PSU_2015_lemipc
##
## Made by nicolas rusig
## Login   <rusign@epitech.net>
##
## Started on  Tue Mar 15 09:38:39 2016 nicolas rusig
## Last update Sun Mar 27 18:02:11 2016 Thomas Martins
##

NAME	= lemipc_bonus

SRC	= src/main.c		\
	  src/error.c		\
	  src/put_pixel.c	\
	  src/draw_mlx.c	\
	  src/init_mlx.c

OBJ	= $(SRC:.c=.o)

INC_DIR = include

GCC	= cc

RM	= rm -f

CFLAGS	+= -W -Wall -Wextra -I$(INC_DIR)

LIBS	= -L/usr/lib64 -lmlx -L/usr/lib64/X11 -lXext -lX11 -lm

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LIBS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
