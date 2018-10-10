/*
** rfc_player_droite.c for droite in /home/mille_j//zappy/serveur/src/rfc_player
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Sat Jul  2 22:10:57 2011 john mille
** Last update Thu Jul  7 19:47:11 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"
#include "my.h"

void			rfc_player_left(__attribute__((unused))t_zappy *z,
					 __attribute__((unused))t_teams *t,
					t_chars *c)
{
  if (c->dir == NORTH)
    c->dir = WEST;
  else if (c->dir == WEST)
    c->dir = SOUTH;
  else if (c->dir == SOUTH)
    c->dir = EAST;
  else if (c->dir == EAST)
    c->dir = NORTH;
  my_xwrite(c->s_chars, "ok\n", 4);
  rfc_graph_ppo_serv(z, c);
}
