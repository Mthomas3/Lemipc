/*
** main.c for  in /home/mart_4/rendu/PSU_2015_lemipc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Mar 14 15:35:34 2016 Thomas Martins
** Last update Sun Mar 27 18:25:08 2016 Thomas Martins
*/

#include <time.h>
#include "lemi.h"

static t_bool	others_players(t_case *o, const char **team)
{
  (void)team;
  o->map = shmat(o->shm_id, NULL, SHM_R | SHM_W);
  if (NULL == o->map)
    return (FALSE);
  return (TRUE);
}

static t_case	*init_game(const char *path, t_case *o,
			   const char **team, t_windows *wind)
{
  (void)wind;
  if ((o->key = ftok(path, 0)) == -1)
    return (NULL);
  o->path = strdup(path);
  o->shm_id = shmget(o->key, MAGIC, SHM_R | SHM_W);
  if (o->shm_id != -1)
    if ((others_players(o, team)) == FALSE)
      return (NULL);
  return (o->map);
}

static t_case	*init_struct(t_case *pic)
{
  if (NULL == (pic = malloc(sizeof(*pic))))
    return (NULL);
  pic->shm_id = 0;
  return (pic);
}

int		main(int ac, const char **av, const char **env)
{
  t_case	*pic;
  t_windows	*windows;
  int		i;

  pic = NULL;
  i = 0;
  windows = NULL;
  if (!*env)
    return (FALSE);
  srand(time(NULL));
  if (FALSE == (check_arguments(ac, av)))
    return (FALSE);
  else if (NULL == (pic = init_struct(pic)))
    return (FALSE);
  if (NULL == (windows = init_windows(windows, 1050, 1050)))
    return (FALSE);
  for (i = 0; i < 1000; i++)
    windows->pix->draw_color[i] = rand() % 0xFFFFFF;
  if (NULL == (windows->map = init_game(av[1], pic, av, windows)))
    return (error("error init game\n"));
  if ((loop(windows)) == FALSE)
    return (FALSE);
  return (TRUE);
}
