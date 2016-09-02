/*
** game.c for  in /home/mart_4/rendu/PSU_2015_lemipc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Fri Mar 18 01:02:48 2016 Thomas Martins
** Last update Sun Mar 27 21:48:54 2016 nicolas rusig
*/

#include <stdlib.h>
#include "lemi.h"

int	g_signal = 1;

int	init_msg(t_case *players)
{
  if ((players->msg_id = msgget(players->key, SHM_R | SHM_W)) != -1)
    return (0);
  else if ((players->msg_id = msgget(players->key,
				     IPC_CREAT | SHM_R | SHM_W)) != -1)
    return (0);
  else
    return (-1);
}

void	func_signal(int sig)
{
  if (sig == SIGINT)
    g_signal = 0;
}

static int	init_player(t_case *play, int team)
{
  blocus(&(play->sops), -1);
  semop(play->sem_id, &(play->sops), 1);
  play->cur_x = (int)(rand() % SIZEX);
  play->cur_y = (int)(rand() % SIZEX);
  while (play->map[(play->cur_y * SIZEX + play->cur_x) % SIZEMAP].nteam != 0)
    {
      play->cur_x = (int)(rand() % SIZEX);
      play->cur_y = (int)(rand() % SIZEY);
    }
  play->map[(play->cur_y * SIZEX + play->cur_x) % SIZEMAP].nteam = team;
  play->is_alive = 1;
  blocus(&(play->sops), 1);
  semop(play->sem_id, &(play->sops), 1);
  return (0);
}

void	blocus(struct sembuf *sops, int lock)
{
  sops->sem_num = 0;
  sops->sem_flg = 0;
  sops->sem_op = lock;
}

t_bool	run_game(t_case *play)
{
  if (too_much(play) > 100)
    return (FALSE);
  init_player(play, play->team_numbers);
  while (play->is_alive && g_signal)
    {
      signal(SIGINT, func_signal);
      usleep(TIMER);
      if (play->first_team == play->team_numbers)
	print_maps(play->map);
      move(play);
    }
  blocus(&(play->sops), -1);
  semop(play->sem_id, &(play->sops), 1);
  play->map[play->cur_y * SIZEX + play->cur_x].nteam = 0;
  blocus(&(play->sops), 1);
  semop(play->sem_id, &(play->sops), 1);
  if (!g_signal && too_much(play) == 0)
    {
      msgctl(play->msg_id, IPC_RMID, NULL);
      semctl(play->sem_id, 1, IPC_RMID);
      shmctl(play->shm_id, IPC_RMID, NULL);
    }
  return (TRUE);
}
