/*
** rfc_player_avance.c for avance in /home/mille_j//zappy/serveur/src/rfc_player
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Sat Jul  2 10:15:50 2011 john mille
** Last update Thu Jul  7 13:46:56 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			rfc_player_avance(t_zappy *z,
					  __attribute__((unused))t_teams *t,
					  t_chars *c)
{
  if (c->dir == EAST && (c->pos_x + 1) == z->map->map_x)
    c->pos_x = 0;
  else if (c->dir == WEST && (c->pos_x) == 0)
    c->pos_x = z->map->map_x - 1;
  else if (c->dir == NORTH && (c->pos_y + 1) == z->map->map_y)
    c->pos_y = 0;
  else if (c->dir == SOUTH && (c->pos_y) == 0)
    c->pos_y = z->map->map_y - 1;
  else
    {
      if (c->dir == EAST)
	c->pos_x += 1;
      else if (c->dir == WEST)
	c->pos_x -= 1;
      else if (c->dir == NORTH)
	c->pos_y += 1;
      else if (c->dir == SOUTH)
	c->pos_y -= 1;
    }
  my_xwrite(c->s_chars, "ok\n", 4);
  rfc_graph_ppo_serv(z, c);
}
