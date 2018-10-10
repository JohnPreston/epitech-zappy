/*
** rfc_player_incantation.c for incantation in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jul  7 20:10:07 2011 john mille
** Last update Sat Jul  9 00:34:47 2011 john mille
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			popup_food(t_zappy *z)
{
  int			i;
  int			j;

  j = 0;
  while (j < z->map->map_y)
    {
      i = 0;
      while (i < z->map->map_x)
	{
	  z->map->cases[i][j].nourriture = set_ressource();
	  i += 1;
	}
      j += 1;
    }
  rfc_graph_mct_serv(z);
}

void			rfc_player_incantation(t_zappy *z,
					       t_teams *t,
					       t_chars *c)
{
  check_incant_end(z, t, c, NULL);
  popup_food(z);
}
