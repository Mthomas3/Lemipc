/*
** error.c for  in /home/mart_4/rendu/PSU_2015_lemipc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Tue Mar 15 17:45:11 2016 Thomas Martins
** Last update Sun Mar 27 17:56:36 2016 Thomas Martins
*/

#include "lemi.h"

t_bool	check_arguments(int ac, const __attribute__((unused))char **arguments)
{
  if (ac != 2)
    return (error("the usage is ./lemipc PATH TEAM_NUMBER\n"));
  return (TRUE);
}

t_bool	error(const char *msg)
{
  fprintf(stderr, msg);
  return (FALSE);
}
