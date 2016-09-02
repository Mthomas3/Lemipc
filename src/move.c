/*
** move.c for  in /home/rusign/rendu/PSU_2015_lemipc
**
** Made by nicolas rusig
** Login   <rusign@epitech.net>
**
** Started on  Wed Mar 23 16:06:02 2016 nicolas rusig
** Last update Sun Mar 27 17:29:28 2016 Thomas Martins
*/

#include "lemi.h"

int	 move_down(t_case *play)
{
  int	tmp_team;

  if ((((play->cur_y + 1) * SIZEX + play->cur_x) < SIZEMAP)
      && (((play->cur_y + 1) * SIZEX + play->cur_x) > 0)
      && play->map[(play->cur_y + 1) * SIZEX + play->cur_x].nteam == 0)
    {
      tmp_team = play->map[play->cur_y * SIZEX + play->cur_x].nteam;
      blocus(&(play->sops), -1);
      semop(play->sem_id, &(play->sops), 1);
      play->map[play->cur_y * SIZEX + play->cur_x].nteam = 0;
      blocus(&(play->sops), 1);
      semop(play->sem_id, &(play->sops), 1);
      blocus(&(play->sops), -1);
      semop(play->sem_id, &(play->sops), 1);
      play->map[(play->cur_y + 1) * SIZEX + play->cur_x].nteam = tmp_team;
      blocus(&(play->sops), 1);
      semop(play->sem_id, &(play->sops), 1);
      play->cur_y++;
      return (0);
    }
  return (-1);
}

int	move_up(t_case *play)
{
  int	tmp_team;

  if ((((play->cur_y - 1) * SIZEX + play->cur_x) < SIZEMAP)
      && (((play->cur_y - 1) * SIZEX + play->cur_x) > 0)
      && play->map[(play->cur_y - 1) * SIZEX + play->cur_x].nteam == 0)
    {
      tmp_team = play->map[play->cur_y * SIZEX + play->cur_x].nteam;
      blocus(&(play->sops), -1);
      semop(play->sem_id, &(play->sops), 1);
      play->map[play->cur_y * SIZEX + play->cur_x].nteam = 0;
      blocus(&(play->sops), 1);
      semop(play->sem_id, &(play->sops), 1);
      blocus(&(play->sops), -1);
      semop(play->sem_id, &(play->sops), 1);
      play->map[(play->cur_y - 1) * SIZEX + play->cur_x].nteam = tmp_team;
      blocus(&(play->sops), 1);
      semop(play->sem_id, &(play->sops), 1);
      play->cur_y--;
      return (0);
    }
  else
    return (-1);
}

int	move_right(t_case *play)
{
  int	tmp_team;

  if (((play->cur_y * SIZEX + (play->cur_x + 1)) < SIZEMAP)
      && ((play->cur_y * SIZEX + (play->cur_x + 1)) > 0)
      && (((play->cur_x + 1) % SIZEX) != 0)
      && play->map[play->cur_y * SIZEX + (play->cur_x + 1)].nteam == 0)
    {
      tmp_team = play->map[play->cur_y * SIZEX + play->cur_x].nteam;
      blocus(&(play->sops), -1);
      semop(play->sem_id, &(play->sops), 1);
      play->map[play->cur_y * SIZEX + play->cur_x].nteam = 0;
      blocus(&(play->sops), 1);
      semop(play->sem_id, &(play->sops), 1);
      blocus(&(play->sops), -1);
      semop(play->sem_id, &(play->sops), 1);
      play->map[play->cur_y * SIZEX + (play->cur_x + 1)].nteam = tmp_team;
      blocus(&(play->sops), 1);
      semop(play->sem_id, &(play->sops), 1);
      play->cur_x++;
      return (0);
    }
  else
    return (-1);
}

int	move_left(t_case *play)
{
  int	tmp_team;

  if (((play->cur_y * SIZEX + (play->cur_x - 1)) < SIZEMAP)
      && ((play->cur_y * SIZEX + (play->cur_x - 1)) > 0)
      && (((play->cur_x - 1) % SIZEX) != 0)
      && play->map[play->cur_y * SIZEX + (play->cur_x - 1)].nteam == 0)
    {
      tmp_team = play->map[play->cur_y * SIZEX + play->cur_x].nteam;
      blocus(&(play->sops), -1);
      semop(play->sem_id, &(play->sops), 1);
      play->map[play->cur_y * SIZEX + play->cur_x].nteam = 0;
      blocus(&(play->sops), 1);
      semop(play->sem_id, &(play->sops), 1);
      blocus(&(play->sops), -1);
      semop(play->sem_id, &(play->sops), 1);
      play->map[play->cur_y * SIZEX + (play->cur_x - 1)].nteam = tmp_team;
      blocus(&(play->sops), 1);
      semop(play->sem_id, &(play->sops), 1);
      play->cur_x--;
      return (0);
    }
  else
    return (-1);
}

void	move(t_case *play)
{
  int	rd;

  rd = rand() % 4;
  if (did_i_died(play, play->team_numbers) == 1)
    return;
  if (strategies(play) == 1)
    return;
  if (rd == 0)
    if (move_down(play) == 0)
      return;
  if (rd == 1)
    if (move_up(play) == 0)
      return;
  if (rd == 2)
    if (move_right(play) == 0)
      return;
  if (rd == 3)
    if (move_left(play) == 0)
      return;
}
