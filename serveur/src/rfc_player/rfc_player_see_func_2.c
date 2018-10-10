/*
** rfc_player_see_func_2.c for see func 2 in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jul  7 05:18:53 2011 john mille
** Last update Fri Jul  8 20:23:58 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

int			there_is_phiras(t_zappy *z,
					__attribute__((unused))t_chars *c,
					int x, int y)
{
  if (z->map->cases[x][y].phiras)
    return (z->map->cases[x][y].phiras);
  return (0);
}

int			there_is_thystame(t_zappy *z,
					  __attribute__((unused))t_chars *c,
					  int x, int y)
{
  if (z->map->cases[x][y].thystame)
    return (z->map->cases[x][y].thystame);
  return (0);
}

int			there_is_player(t_zappy *z,
					__attribute__((unused))t_chars *c,
					int x, int y)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;
  int			nb;

  nb = 0;
  t_tmp = z->teams;
  t_tmp = t_tmp->next;
  t_tmp = t_tmp->next;
  while (t_tmp)
    {
      c_tmp = t_tmp->chars;
      while (c_tmp)
	{
	  if ((c_tmp->is_ghost == 1 || c->is_ghost == 0)
	      && c_tmp->is_egg == 0 &&
	      c_tmp->pos_x == x && c_tmp->pos_y == y)
	    nb += 1;
	  c_tmp = c_tmp->next;
	}
      t_tmp = t_tmp->next;
    }
  return (nb);
}
