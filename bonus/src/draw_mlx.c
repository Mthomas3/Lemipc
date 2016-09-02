/*
** draw_mlx.c for  in /home/mart_4/rendu/PSU_2015_lemipc/bonus/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 27 16:30:56 2016 Thomas Martins
** Last update Mon Mar 28 18:15:53 2016 Thomas Martins
*/

#include <time.h>
#include "lemi.h"

static int	key_bind(int key, t_windows __attribute__((unused))*wind)
{
  if (key == 65307)
    {
      printf("thanks for watching this game!!\n");
      exit(0);
    }
  return (TRUE);
}

static int	expose(t_windows *wind)
{
  IMG_TOWIN(wind->mlx_ptr, wind->win_ptr, wind->pix->pixel, 0, 0);
  return (TRUE);
}

int	loop(t_windows *wind)
{
  if ((HOOK(wind->win_ptr, KeyPress, KeyPressMask, key_bind, wind)) == FALSE)
    return (FALSE);
  mlx_expose_hook(wind->win_ptr, &expose, wind);
  mlx_loop_hook(wind->mlx_ptr, draw_map, wind);
  mlx_loop(wind->mlx_ptr);
  return (TRUE);
}

static int	draw_square(t_windows *wind, int color, int pos_x, int pos_y)
{
  int		x;
  int		y;

  for (x = pos_x; x < pos_x + SQUAREX; ++x)
    {
      for (y = pos_y; y < pos_y + SQUAREY; ++y)
	{
	  my_put_pixel(wind, x, y, color);
	}
    }
  return (TRUE);
}

int		draw_map(void *data)
{
  int		x;
  t_windows	*wind;
  int		tmp;

  wind = (t_windows *)data;
  for (x = 0; (size_t)x < SIZEMAP; x++)
    {
      tmp = wind->map[x].nteam;
      if (tmp <= 1000)
	draw_square(wind,
		    wind->pix->draw_color[tmp],
		    (x % SIZEX) * 35,
		    (x / SIZEX) * 35);
      else
	draw_square(wind,
		    wind->pix->draw_color[50],
		    (x % SIZEX) * 35,
		    (x / SIZEX) * 35);
    }
  mlx_put_image_to_window(wind->mlx_ptr,
			  wind->win_ptr, wind->pix->pixel, 0, 0);
  return (TRUE);
}
