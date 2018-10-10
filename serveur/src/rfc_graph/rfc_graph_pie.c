/*
** rfc_graph_pex.c for pex.c in /home/mille_j//zappy/serveur/src/rfc_graph
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 08:28:10 2011 john mille
** Last update Fri Jul  8 18:11:44 2011 john mille
*/

#include <stdio.h>
#include "zappy.h"

void			rfc_graph_pie(t_zappy *z, t_chars *incant, int result)
{
  t_chars		*c_tmp;

  c_tmp = z->teams->next->chars;
  while (c_tmp)
    {
      dprintf(c_tmp->s_chars, "pie %d %d %d\n",
	      incant->pos_x, incant->pos_y, result);
      c_tmp = c_tmp->next;
    }
}
