/*
** rfc_player_invent.c for invent in /home/mille_j//zappy/serveur/src/rfc_player
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Mon Jul  4 20:56:14 2011 john mille
** Last update Sun Jul 10 11:08:12 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "zappy.h"
#include "my.h"

void			rfc_player_invent( __attribute__((unused))t_zappy *z,
					   t_teams *t,
					   t_chars *c)
{
  char			answer1[128];
  char			answer2[128];

  memset(answer1, 0, 128);
  memset(answer2, 0, 128);
  snprintf(answer1, 128, "{nourriture %d,linemate %d,deraumere %d,sibur %d,",
	   c->invent->nourriture, c->invent->linemate, c->invent->deraumere,
	   c->invent->sibur);
  snprintf(answer2, 128, "%s mendiane %d,phiras %d,thystame %d}\n",
	   answer1, c->invent->mendiane, c->invent->phiras,
	   c->invent->thystame);
  if ((my_xwrite(c->s_chars, answer2,
		 my_strlen(answer2))) < my_strlen(answer2))
    t->chars = delete_char(t, c, 1);
}
