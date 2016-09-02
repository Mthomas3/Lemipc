/*
** put_pixel.c for  in /home/mart_4/rendu/PSU_2015_lemipc/bonus/src
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 27 01:16:06 2016 Thomas Martins
** Last update Sun Mar 27 01:24:46 2016 Thomas Martins
*/

#include "lemi.h"

int	my_put_pixel(t_windows *wind, int x, int y, int color)
{
  int	a;
  int	b;
  int	c;
  int	d;

  if (x < 0 || y >= wind->height || y < 0 || x >= wind->width)
    return (-1);
  d = x * wind->pix->bpp / 8 + y * wind->pix->sizeline;
  a = (color >> 16) & 255;
  b = (color >> 8) & 255;
  c = color & 255;
  wind->pix->data[d + 0] = c;
  wind->pix->data[d + 1] = b;
  wind->pix->data[d + 2] = a;
  return (TRUE);
}
