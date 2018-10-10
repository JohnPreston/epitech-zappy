/*
** rfc_player_connec_nbr.c for connect nbr in /home/mille_j//zappy/serveur/src/rfc_player
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jul  5 00:18:08 2011 john mille
** Last update Thu Jul  7 13:47:05 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"

void			rfc_player_connect_nbr(__attribute__((unused))t_zappy *z,
					       t_teams *t,
					       t_chars *c)
{
  dprintf(c->s_chars, "%d\n", t->max_members);
}
