/*
** print_mlx.c for  in /home/mart_4/rendu/PSU_2015_lemipc/bonus/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 27 16:47:02 2016 Thomas Martins
** Last update Sun Mar 27 17:41:45 2016 Thomas Martins
*/

#include "lemi.h"

static t_windows	*init_mlx(t_windows *wind)
{
  if (!(wind->mlx_ptr = INIT()))
    return (NULL);
  if (!(wind->pix->pixel = NEW_IMG(wind->mlx_ptr, wind->width, wind->height)))
    return (NULL);
  if (!(wind->pix->data = GET_DATA(wind->pix->pixel,
				   &(wind->pix->bpp), &(wind->pix->sizeline),
				   &(wind->pix->endian))))
    return (NULL);
  if (!(wind->win_ptr = NEW_WIN(wind, "LEMIPC")))
    return (NULL);
  return (wind);
}

t_windows	*init_windows(t_windows *wind, size_t x, size_t y)
{
  if (NULL == (wind = malloc(sizeof(*wind))))
    return (NULL);
  else if (NULL == (wind->pix = malloc(sizeof(*wind->pix))))
    return (NULL);
  wind->width = x;
  wind->height = y;
  return (init_mlx(wind));
}
