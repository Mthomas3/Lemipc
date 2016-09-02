/*
** lemipc.h for  in /home/mart_4/rendu/PSU_2015_lemipc
**
** Made by Thomas Martins
** Login   <mart_4@epitech.net>
**
** Started on  Sun Mar 27 21:17:58 2016 Thomas Martins
** Last update Sun Mar 27 21:22:09 2016 Thomas Martins
*/

#ifndef LEMIPC_H__
# define LEMIPC_H__

/*
** This is the structure that you must use to represent a champion
** You can EXTEND it, but never change the base fields that are already
** there. Failure to comply will result in a project failure.
**
** Your shared memory must be an array of this structure.
** The size must be of width * height * sizeof(struct s_case)
*/

struct			s_case
{
  /*
  ** Position in the map
  */
  int			x;
  int			y;

  /*
  ** Team number
  ** A value of 0 means that the case is unnocupied
  */
  int			nteam;

  /*
  ** Add fields there
  */
  int			cur_x;
  int			cur_y;
  int			is_alive;
  int			target_x;
  int			target_y;
  int			key;
  int			shm_id;
  int			sem_id;
  int			msg_id;
  int			team_numbers;
  int			first_team;
  const char		*path;
  struct sembuf		sops;
  struct s_case		*map;
};

/*
** Note: We MIGHT add fields to the structure so don't use raw numbers for
** your shm length, use the sizeof keyword
*/

#endif
