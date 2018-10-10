/*
** rfc_graph_pni.c for pni in /home/mille_j//zappy/serveur/src/rfc_graph
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 08:59:26 2011 john mille
** Last update Tue Jul  5 03:16:02 2011 john mille
*/

#include <stdio.h>
#include "zappy.h"

void			rfc_graph_pdi(t_zappy *z, t_chars *c)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;

  t_tmp = z->teams;
  t_tmp = t_tmp->next;
  c_tmp = t_tmp->chars;
  while (c_tmp)
    {
      dprintf(c_tmp->s_chars, "pdi %d\n", c->id);
      c_tmp = c_tmp->next;
    }
}
