/*
** main.c for  in /home/mart_4/rendu/PSU_2015_lemipc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Mar 14 15:35:34 2016 Thomas Martins
** Last update Sun Mar 27 21:09:11 2016 Thomas Martins
*/

#include <time.h>
#include "lemi.h"

static t_bool	init_players(t_case *players, const char **team)
{
  int		__attribute__((unused))result;

  result = 0;
  players->map = NULL;
 if ((players->sem_id = semget(players->key, 1, SHM_R |
			       SHM_W | IPC_CREAT)) == -1)
    return (FALSE);
  if ((players->shm_id = shmget(players->key, MAGIC, IPC_CREAT
				| SHM_R | SHM_W)) == -1)
    return (FALSE);
  if (init_msg(players) == -1)
    return (FALSE);
  if ((players->map = shmat(players->shm_id, NULL, SHM_R | SHM_W)) == NULL)
    return (FALSE);
  players->map = init_map(players->map);
  if ((-1) == (semctl(players->sem_id, 0, SETVAL, 1)))
    return (FALSE);
  players->first_team = atoi(team[2]);
  players->team_numbers = players->first_team;
  if (FALSE == (run_game(players)))
    return (FALSE);
  return (TRUE);
}

static t_bool	others_players(t_case *o, const char **team)
{
  o->map = shmat(o->shm_id, NULL, SHM_R | SHM_W);
  if (NULL == o->map)
    return (FALSE);
  o->team_numbers = atoi(team[2]);
  if (init_msg(o) == -1)
    return (FALSE);
  if (FALSE == (run_game(o)))
    return (FALSE);
  return (TRUE);
}

static t_bool	init_game(const char *path, t_case *o, const char **team)
{
  if ((o->key = ftok(path, 0)) == -1)
    return (error("error with ftok"));
  o->path = strdup(path);
  o->shm_id = shmget(o->key, MAGIC, SHM_R | SHM_W);
  if ((o->shm_id == - 1 ? init_players(o, team) :
       others_players(o, team)) == FALSE)
    return (FALSE);
  print_maps(o->map);
  return (TRUE);
}

static t_case	*init_struct(t_case *pic)
{
  if (NULL == (pic = malloc(sizeof(*pic))))
    return (NULL);
  pic->shm_id = 0;
  return (pic);
}

int		main(int ac, const char **av)
{
  t_case	*pic;

  pic = NULL;
  srand(time(NULL));
  if (FALSE == (check_arguments(ac, av)))
    return (FALSE);
  else if (NULL == (pic = init_struct(pic)))
    return (FALSE);
  else if (FALSE == (init_game(av[1], pic, av)))
    return (error("error init game\n"));
  return (TRUE);
}
