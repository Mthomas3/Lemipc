/*
** comunicate.c for  in /home/rusign/PSU_2015_lemipc/src
**
** Made by nicolas rusig
** Login   <rusign@epitech.net>
**
** Started on  Sat Mar 26 23:20:04 2016 nicolas rusig
** Last update Sun Mar 27 21:39:56 2016 nicolas rusig
*/

#include <string.h>
#include "lemi.h"

static int	get_msgq(t_case *play, t_msgbuf *msgq)
{
  int		res;

  blocus(&(play->sops), -1);
  semop(play->sem_id, &(play->sops), 1);
  res = msgrcv(play->msg_id, msgq, sizeof(t_msgbuf *),
	       play->team_numbers, IPC_NOWAIT);
  blocus(&(play->sops), 1);
  semop(play->sem_id, &(play->sops), 1);
  return (res);
}

static void	send_msgq(t_case *play, t_msgbuf *msgq)
{
  blocus(&(play->sops), -1);
  semop(play->sem_id, &(play->sops), 1);
  if (msgsnd(play->msg_id, msgq, sizeof(t_msgbuf *),
	     IPC_NOWAIT) == -1)
    printf("fail send\n");;
  blocus(&(play->sops), 1);
  semop(play->sem_id, &(play->sops), 1);
}

static int	check_msgq(t_case *play, char *msg)
{
  int		x;
  int		y;

  x = atoi(strtok(msg, ","));
  y = atoi(strtok(msg, ","));
  if (play->map[y * SIZEX + x].nteam != 0
      && play->map[y * SIZEX + x].nteam != play->team_numbers)
    {
      play->target_x = x;
      play->target_y = y;
      return (1);
    }
  else
    return (0);
}

int		got_msgq(t_case *play)
{
  t_msgbuf	msgq;

  if (!get_msgq(play, &msgq))
    {
      if (check_msgq(play, &(msgq.mtext[0])))
	{
	  send_msgq(play, &msgq);
	  return (1);
	}
      else
	{
	  if (find_enemies(play) == 1)
	    {
	      send_target(play);
	      return (1);
	    }
	}
    }
  return (-1);
}

void		send_target(t_case *play)
{
  t_msgbuf	msgq;

  bzero(&msgq, sizeof(msgq));
  msgq.mtype = play->team_numbers;
  sprintf(msgq.mtext, "%d,%d", play->target_x, play->target_y);
  send_msgq(play, &msgq);
}
