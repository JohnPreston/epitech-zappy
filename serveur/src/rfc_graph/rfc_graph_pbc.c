/*
** rfc_graph_pex.c for pex.c in /home/mille_j//zappy/serveur/src/rfc_graph
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 08:28:10 2011 john mille
** Last update Thu Jul  7 17:40:34 2011 john mille
*/

#include <stdio.h>
#include "zappy.h"

void			rfc_graph_pbc(t_zappy *z, t_chars *c, char *msg)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;

  t_tmp = z->teams;
  t_tmp = t_tmp->next;
  c_tmp = t_tmp->chars;
  while (c_tmp)
    {
      dprintf(c_tmp->s_chars, "pbc %d %s\n", c->id, msg);
      c_tmp = c_tmp->next;
    }
}
