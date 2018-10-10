/*
** rfc_graph_pnw.c for pnw in /home/mille_j//zappy/serveur/src/rfc_graph
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 07:19:22 2011 john mille
** Last update Thu Jul  7 19:08:19 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"

void			rfc_graph_pnw(t_zappy *z, t_teams *t, t_chars *c)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;

  t_tmp = z->teams;
  t_tmp = t_tmp->next;
  c_tmp = t_tmp->chars;
  while (c_tmp)
    {
      dprintf(c_tmp->s_chars, "pnw %d %d %d %d %d %s\n",
	      c->id, c->pos_y, c->pos_y, c->dir,
	      c->level, t->name);
      c_tmp = c_tmp->next;
    }
}
