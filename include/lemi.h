/*
** lemi.h for  in /home/rusign/rendu/UNIX/PSU_2015_lemipc/include
**
** Made by nicolas rusig
** Login   <rusign@epitech.net>
**
** Started on  Tue Mar 15 09:35:55 2016 nicolas rusig
** Last update Sun Mar 27 20:17:47 2016 nicolas rusig
*/

#ifndef LEMI_H_
# define LEMI_H_

# include <sys/types.h>
# include <sys/ipc.h>
# include <stdlib.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <sys/msg.h>

# include "../lemipc.h"
# include "struct.h"

typedef struct s_case t_case;

# define TIMER 500000
# define MAGIC (sizeof(struct s_case) * SIZEMAP)

t_bool		check_arguments(int, const char **);
t_bool		error(const char *);
char		**generate_tab(char **tab);
char		**copy_string(char **tab, const char *);
void		print_maps(t_case *);
t_case		*init_map(t_case *);
t_bool		run_game(t_case *);
t_bool		print_map(t_case *);
void		blocus(struct sembuf *sops, int lock);
void		move(t_case *play);
int		did_i_died(t_case *play, int team);
int		strategies(t_case *play);
int		find_enemies(t_case *play);
void		send_target(t_case *play);
int		got_msgq(t_case *play);
int		move_down(t_case *play);
int		move_up(t_case *play);
int		move_right(t_case *play);
int		move_left(t_case *play);
int		init_msg(t_case *players);
int		too_much(t_case *map);

#endif
