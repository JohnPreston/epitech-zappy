/*
** rfc_graph_pex.c for pex.c in /home/mille_j//zappy/serveur/src/rfc_graph
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 08:28:10 2011 john mille
** Last update Fri Jul  8 10:41:30 2011 john mille
*/

#include <stdio.h>
#include "zappy.h"

void			rfc_graph_pgt(t_zappy *z, t_chars *c, int res)
{
  t_chars		*c_tmp;

  c_tmp = z->teams->next->chars;
  while (c_tmp)
    {
      if ((dprintf(c_tmp->s_chars, "pgt %d %d\n", c->id, res)) < 0)
	z->teams->next->chars = delete_char(z->teams->next, c_tmp, 1);
      c_tmp = c_tmp->next;
    }
}
