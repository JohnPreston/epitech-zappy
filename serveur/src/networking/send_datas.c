/*
** send_datas.c for send_datas in /home/mille_j//zappy/serveur/src/networking
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Mon Jul  4 11:40:37 2011 john mille
** Last update Fri Jul  8 18:42:23 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			send_datas(t_zappy *z, t_teams *t, t_chars *c)
{
  if (t->id == 1)
    graph_first_connect(z);
  else if (t->id > 2)
    {
      rfc_graph_pnw(z, t, c);
      if ((dprintf(c->s_chars, "%d\n%d %d\n", t->max_members,
		   z->map->map_x, z->map->map_y)) <= 0)
	t->chars = delete_char(t, c, 1);
    }
}
