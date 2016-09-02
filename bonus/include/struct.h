/*
** struct.h for  in /home/mart_4/rendu/PSU_2015_lemipc/include
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Mon Mar 14 15:32:13 2016 Thomas Martins
** Last update Sun Mar 27 18:08:49 2016 Thomas Martins
*/

#ifndef STRUCT_H_
# define STRUCT_H_

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <X11/Xlib.h>
#include <mlx.h>

# define	SIZEX 30
# define	SIZEY 30
# define	SIZEMAP ((SIZEX) * (SIZEY))
# define	SQUAREX	30
# define	SQUAREY	30

# define	NEW_WIN(X, Y) mlx_new_window((X)->mlx_ptr, (X)->width, (X)->height, Y)
# define	INIT	mlx_init
# define	NEW_IMG	mlx_new_image
# define	GET_DATA mlx_get_data_addr
# define	LOOP	mlx_loop
# define	IMG_TOWIN mlx_put_image_to_window
# define	HOOK	mlx_hook

typedef enum	e_bool	t_bool;
typedef struct	s_pixel	t_pixel;
typedef struct	s_windows t_windows;

enum		e_bool
  {
    FALSE =  -1,
    TRUE = 0
  };

typedef struct	s_msgbuf
{
  long		mtype;
  char		mtext[32];
}		t_msgbuf;

struct		s_pixel
{
  int		*pixel;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
  int		color;
  int		draw_color[1000];
};

struct		s_windows
{
  void		*mlx_ptr;
  void		*win_ptr;
  t_pixel	*pix;
  int		width;
  int		height;
  int		shm_id;
  int		key;
  t_case	*map;
};

int		my_put_pixel(t_windows *, int, int, int);
int		draw_map(void *data);
int		loop(t_windows *wind);
t_windows	*init_windows(t_windows *wind, size_t x, size_t y);

#endif
