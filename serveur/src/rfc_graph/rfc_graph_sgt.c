/*
** rfc_graph_sgt.c for sgt in /home/mille_j//zappy/serveur/src/parsing
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 04:01:36 2011 john mille
** Last update Fri Jul  8 05:35:05 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			rfc_graph_sgt(t_zappy *z,
				      __attribute__((unused))t_teams *t,
				      t_chars *c,
				      __attribute__((unused))char *buff)
{
  dprintf(c->s_chars, "sgt %d\n", z->map->time);
}

void			rfc_graph_sgt_serv(t_zappy *z)
{
  t_chars		*c_tmp;

  c_tmp = z->teams->next->chars;
  while (c_tmp)
    {
      if ((dprintf(c_tmp->s_chars, "sgt %d\n", z->map->time)) <= 0)
	z->teams->next->chars = delete_char(z->teams->next, c_tmp, 1);
      c_tmp = c_tmp->next;
    }
}
