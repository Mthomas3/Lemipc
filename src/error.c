/*
** error.c for  in /home/mart_4/rendu/PSU_2015_lemipc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Tue Mar 15 17:45:11 2016 Thomas Martins
** Last update Sun Mar 27 20:12:52 2016 nicolas rusig
*/

#include "lemi.h"

int	too_much(t_case *play)
{
  int	res;
  int	i;

  res = 0;
  for (i = 0; i < SIZEMAP; i++)
    {
      if (play->map[i].nteam != 0)
	res++;
    }
  return (res);
}

t_bool	check_arguments(int ac, const char **av)
{
  if (ac != 3)
    return (error("the usage is ./lemipc PATH TEAM_NUMBER\n"));
  if (atoi(av[2]) <= 0)
    return (error("TEAM_NUMBER > 0\n"));
  return (TRUE);
}

t_bool	error(const char *msg)
{
  fprintf(stderr, msg);
  return (FALSE);
}
