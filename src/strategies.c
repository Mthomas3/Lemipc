/*
** strategies.c for  in /home/rusign/PSU_2015_lemipc/src
**
** Made by nicolas rusig
** Login   <rusign@epitech.net>
**
** Started on  Sat Mar 26 22:57:18 2016 nicolas rusig
** Last update Sun Mar 27 17:30:29 2016 Thomas Martins
*/

#include "lemi.h"

int	find_enemies(t_case *play)
{
  int	x;
  int	y;
  int	i;

  i = 0;
  for (y = 0; y < (SIZEY); y++)
    {
      for (x = 0; x < (SIZEX); x++)
        {
          if (play->map[i].nteam != 0 && play->map[i].nteam
	      != play->team_numbers)
	    {
	      play->target_x = x;
	      play->target_y = y;
	      return (1);
	    }
	  i++;
        }
    }
  return (-1);
}

static int	move_to_target(t_case *play)
{
  if (play->target_y > play->cur_y && move_down(play) == 0)
    return (1);
  if (play->target_y < play->cur_y && move_up(play) == 0)
    return (1);
  if (play->target_x < play->cur_x && move_left(play) == 0)
    return (1);
  if (play->target_x > play->cur_x && move_right(play) == 0)
    return (1);
  return (-1);
}

int	strategies(t_case *play)
{
  if (got_msgq(play) == -1)
    {
      if (find_enemies(play) == -1)
	return (-1);
      else
	{
	  send_target(play);
	  if (move_to_target(play) == -1)
	    return (-1);
	  return (1);
	}
    }
  else
    {
      if (move_to_target(play) == -1)
	return (-1);
    }
  return (-1);
}
