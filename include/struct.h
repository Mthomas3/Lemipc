/*
** struct.h for  in /home/mart_4/rendu/PSU_2015_lemipc/include
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Mar 14 15:32:13 2016 Thomas Martins
** Last update Sun Mar 27 19:16:25 2016 nicolas rusig
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

# define SIZEX 30
# define SIZEY 30
# define SIZEMAP ((SIZEX) * (SIZEY))

typedef enum	e_bool	t_bool;

enum			e_bool
  {
    FALSE =  -1,
    TRUE = 0
  };

typedef struct		s_msgbuf
{
  long			mtype;
  char			mtext[32];
}			t_msgbuf;

#endif
