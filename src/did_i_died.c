/*
** did_i_died.c for  in /home/rusign/rendu/PSU_2015_lemipc/src
**
** Made by nicolas rusig
** Login   <rusign@epitech.net>
**
** Started on  Sat Mar 26 17:57:36 2016 nicolas rusig
** Last update Sun Mar 27 17:45:57 2016 Thomas Martins
*/

#include "lemi.h"

static int	check_enemies_regular(t_case *play, int team, int nb_enemies)
{
  if ((((play->cur_y + 1) * SIZEX + play->cur_x) < SIZEMAP)
      && (((play->cur_y + 1) * SIZEX + play->cur_x) > 0)
      && (play->map[(play->cur_y + 1) * SIZEX + play->cur_x].nteam != 0)
      && (play->map[(play->cur_y + 1) * SIZEX + play->cur_x].nteam != team))
    nb_enemies++;
  if ((((play->cur_y - 1) * SIZEX + play->cur_x) < SIZEMAP)
      && (((play->cur_y - 1) * SIZEX + play->cur_x) > 0)
      && play->map[(play->cur_y - 1) * SIZEX + play->cur_x].nteam != 0
      && play->map[(play->cur_y - 1) * SIZEX + play->cur_x].nteam != team)
    nb_enemies++;
  if (((play->cur_y * SIZEX + (play->cur_x + 1)) < SIZEMAP)
      && ((play->cur_y * SIZEX + (play->cur_x + 1)) > 0)
      && (((play->cur_x + 1) < SIZEX))
      && play->map[play->cur_y * SIZEX + (play->cur_x + 1)].nteam != 0
      && play->map[play->cur_y * SIZEX + (play->cur_x + 1)].nteam != team)
    nb_enemies++;
  if (((play->cur_y * SIZEX + (play->cur_x - 1)) < SIZEMAP)
      && ((play->cur_y * SIZEX + (play->cur_x - 1)) > 0)
      && (((play->cur_x + 1) >= SIZEX))
      && play->map[play->cur_y * SIZEX + (play->cur_x - 1)].nteam != 0
      && play->map[play->cur_y * SIZEX + (play->cur_x - 1)].nteam != team)
    nb_enemies++;
  return (nb_enemies);
}

static int	check_enemies_diago(t_case *play, int team, int nb_enemies)
{
  if ((((play->cur_y + 1) * SIZEX + (play->cur_x + 1)) < SIZEMAP)
      && (((play->cur_y + 1) * SIZEX + play->cur_x + 1) > 0)
      && (play->cur_y + 1) < SIZEY && (play->cur_x + 1) < SIZEX
      && play->map[(play->cur_y + 1) * SIZEX + (play->cur_x + 1)].nteam != 0
      && play->map[(play->cur_y + 1) * SIZEX + (play->cur_x + 1)].nteam != team)
    nb_enemies++;
  if ((((play->cur_y - 1) * SIZEX + (play->cur_x + 1)) < SIZEMAP)
      && (((play->cur_y - 1) * SIZEX + (play->cur_x + 1)) > 0)
      && (play->cur_y - 1) >= 0  && (play->cur_x + 1) < SIZEX
      && play->map[(play->cur_y - 1) * SIZEX + (play->cur_x + 1)].nteam != 0
      && play->map[(play->cur_y - 1) * SIZEX + (play->cur_x + 1)].nteam != team)
    nb_enemies++;
  if ((((play->cur_y + 1) * SIZEX + (play->cur_x - 1)) < SIZEMAP)
      && (((play->cur_y + 1) * SIZEX + play->cur_x - 1) > 0)
      && (play->cur_y + 1) < SIZEY && (play->cur_x - 1) >= 0
      && play->map[(play->cur_y + 1) * SIZEX + (play->cur_x - 1)].nteam != 0
      && play->map[(play->cur_y + 1) * SIZEX + (play->cur_x - 1)].nteam != team)
    nb_enemies++;
  if ((((play->cur_y - 1) * SIZEX + (play->cur_x - 1)) < SIZEMAP)
      && (((play->cur_y - 1) * SIZEX + (play->cur_x - 1)) > 0)
      && (play->cur_y - 1) >= 0  && (play->cur_x - 1) >= 0
      && play->map[(play->cur_y - 1) * SIZEX + (play->cur_x - 1)].nteam != 0
      && play->map[(play->cur_y - 1) * SIZEX + (play->cur_x - 1)].nteam != team)
    nb_enemies++;
  return (nb_enemies);
}

int		did_i_died(t_case *play, int team)
{
  int		nb_enemies;

  nb_enemies = 0;
  nb_enemies += check_enemies_regular(play, team, 0);
  nb_enemies += check_enemies_diago(play, team, 0);
  if (nb_enemies >= 2)
    {
      printf("DEAD == > team %d, x: %d, y: %d\n",
             play->map[play->cur_y * SIZEX + play->cur_x].nteam,
             play->cur_x, play->cur_y);
      play->is_alive = 0;
      return (1);
    }
  return (0);
}
