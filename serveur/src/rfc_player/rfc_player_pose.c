/*
** rfc_player_pose.c for zpy in /home/chen_b//zappy/serveur/src/rfc_player
**
** Made by laurent chen
** Login   <chen_b@epitech.net>
**
** Started on  Tue Jul  5 16:52:28 2011 laurent chen
** Last update Fri Jul  8 10:38:40 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"
#include "my.h"

static t_ressource		gl_ressource_pose[] = {
  {1, "nourriture", put_food},
  {2, "linemate", put_linemate},
  {3, "deraumere", put_deraumere},
  {4, "sibur", put_sibur},
  {5, "mendiane", put_mendiane},
  {6, "phiras", put_phiras},
  {7, "thystame", put_thystame},
  {0, NULL, NULL},
};

void				put_food(t_chars *c, t_zappy *z)
{
  if (c->invent->nourriture > 0)
    {
      c->invent->nourriture -= 1;
      z->map->cases[c->pos_x][c->pos_y].nourriture += 1;
      rfc_graph_mct_serv(z);
      rfc_graph_pin_serv(z);
      my_xwrite(c->s_chars, "ok\n", 4);
    }
  else
    my_xwrite(c->s_chars, "ko\n", 4);
}

void				put_linemate(t_chars *c, t_zappy *z)
{
  if (c->invent->linemate > 0)
    {
      c->invent->linemate -= 1;
      z->map->cases[c->pos_x][c->pos_y].linemate += 1;
      rfc_graph_mct_serv(z);
      rfc_graph_pin_serv(z);
      my_xwrite(c->s_chars, "ok\n", 4);
    }
  else
    my_xwrite(c->s_chars, "ko\n", 4);
}

void				rfc_player_pose(t_zappy *z,
						__attribute__((unused))t_teams *t,
						t_chars *c)
{
  char				**tab;
  char				*cmd;
  int				i;

  i = 0;
  cmd = c->actions->cmd;
  if (nb_words(cmd) == 2)
    {
      tab = str_parser(cmd);
      while (gl_ressource_pose[i].id)
	{
	  if (my_strcmp(tab[1], gl_ressource_pose[i].name) == 0)
	    {
	      gl_ressource_pose[i].func(c, z);
	      rfc_graph_pdr(z, c, (gl_ressource_pose[i].id - 1));
	      return ;
	    }
	  i += 1;
	}
    }
}
