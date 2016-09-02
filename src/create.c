/*
** create.c for  in /home/mart_4/rendu/PSU_2015_lemipc/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Thu Mar 17 22:20:18 2016 Thomas Martins
** Last update Sun Mar 27 20:15:56 2016 nicolas rusig
*/

#include "lemi.h"

char		**create_colo_tab()
{
  char		**tab;

  if ((tab = malloc(6 * sizeof(char *))) == NULL)
    exit(-1);
  tab[0] = strdup(" %d");
  tab[1] = strdup(" \033[31m%d\033[0m");
  tab[2] = strdup(" \033[32m%d\033[0m");
  tab[3] = strdup(" \033[33m%d\033[0m");
  tab[4] = strdup(" \033[34m%d\033[0m");
  tab[5] = strdup(" \033[35m%d\033[0m");
  tab[6] = strdup(" \036[32m%d\033[0m");
  return (tab);
}

t_case	*init_map(t_case *map)
{
  int	y;
  int	x;
  int	i;

  i = 0;
  for (y = 0; y < (SIZEY); y++)
    {
      for (x = 0; x < (SIZEX); x++)
  	{
  	  map[i].nteam = 0;
  	  map[i].x = x;
  	  map[i++].x = y;
  	}
    }
  return (map);
}

void	print_maps(t_case *map)
{
  int	x;
  char	**color_tab;

  color_tab = create_colo_tab();
  printf("\033[H\033[2J");
  for (x = 0; (size_t)x < SIZEMAP; ++x)
    {
      if (!(x % SIZEX))
      	printf("\n");
      if (map[x].nteam != 0 && map[x].nteam % 6 == 0)
	printf(color_tab[(map[x].nteam % 6) + 1], map[x].nteam);
      else
	printf(color_tab[map[x].nteam % 6], map[x].nteam);
    }
  printf("\n");
  free(color_tab);
}

char	**generate_tab(char **tab)
{
  int	a;

  tab = NULL;
  if (NULL == (tab = malloc(sizeof(char *) * SIZEX)))
    return (NULL);
  for (a = 0; a < SIZEX - 1; ++a)
    if (NULL == (tab[a] = malloc(sizeof(char) * SIZEY)))
      return (NULL);
  tab[SIZEY - 1] = NULL;
  return (tab);
}

char	**copy_string(char **tab, const char *copy)
{
  int	a;
  int	x;
  int	y;

  for (x = 0, y = 0, a = 0; copy[a] != '\0'; ++a, ++x)
    x < SIZEX - 1 ? tab[y][x] = copy[a] : (tab[y][x] = '\0',
					   x = 0, y++, tab[y][x] = copy[a]);
  return (tab);
}
