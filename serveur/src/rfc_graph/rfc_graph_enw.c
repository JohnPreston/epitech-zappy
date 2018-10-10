/*
** rfc_graph_pex.c for pex.c in /home/mille_j//zappy/serveur/src/rfc_graph
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 08:28:10 2011 john mille
** Last update Mon Jul  4 19:53:44 2011 john mille
*/

#include <stdio.h>
#include "zappy.h"

void			rfc_graph_enw(t_zappy *z, t_chars *c, t_chars *egg)
{
  t_teams		*t;
  t_chars		*c_tmp;

  t = z->teams;
  t = t->next;
  c_tmp = t->chars;
  while (c_tmp)
    {
      dprintf(c_tmp->s_chars, "enw %d %d %d %d\n",
	      egg->id, c->id, egg->pos_x, egg->pos_y);
      c_tmp = c_tmp->next;
    }
}
