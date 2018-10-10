/*
** rfc_graph_pex.c for pex.c in /home/mille_j//zappy/serveur/src/rfc_graph
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 08:28:10 2011 john mille
** Last update Thu Jul  7 19:07:07 2011 john mille
*/

#include <stdio.h>
#include "zappy.h"

void			rfc_graph_seg(t_chars *c)
{
  dprintf(c->s_chars, "seg %d\n", c->id);
}
