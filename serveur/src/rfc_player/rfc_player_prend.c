/*
** rfc_player_prendre.c for zpy in /home/chen_b//zappy/serveur/src/rfc_player
**
** Made by laurent chen
** Login   <chen_b@epitech.net>
**
** Started on  Tue Jul  5 15:00:09 2011 laurent chen
** Last update Sat Jul  9 11:51:38 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"
#include "my.h"

static t_ressource		gl_ressource_prend[] = {
  {1, "nourriture", add_food},
  {2, "linemate", add_linemate},
  {3, "deraumere", add_deraumere},
  {4, "sibur", add_sibur},
  {5, "mendiane", add_mendiane},
  {6, "phiras", add_phiras},
  {7, "thystame", add_thystame},
  {0, NULL, NULL},
};

void			add_food(t_chars *c, t_zappy *z)
{
  if (z->map->cases[c->pos_x][c->pos_y].nourriture > 0)
    {
      c->invent->nourriture += 1;
      z->map->cases[c->pos_x][c->pos_y].nourriture -= 1;
      rfc_graph_bct_serv(z, c->pos_x, c->pos_y);
      rfc_graph_pin_serv(z);
      my_xwrite(c->s_chars, "ok\n", 4);
    }
  else
    my_xwrite(c->s_chars, "ko\n", 4);
}

void			add_linemate(t_chars *c, t_zappy *z)
{
  if (z->map->cases[c->pos_x][c->pos_y].linemate)
    {
      c->invent->linemate += 1;
      z->map->cases[c->pos_x][c->pos_y].linemate -= 1;
      rfc_graph_bct_serv(z, c->pos_x, c->pos_y);
      rfc_graph_pin_serv(z);
      my_xwrite(c->s_chars, "ok\n", 4);
    }
  else
    my_xwrite(c->s_chars, "ko\n", 4);
}

void			rfc_player_prend(t_zappy *z,
					 __attribute__((unused))t_teams *t,
					 t_chars *c)
{
  char			**tab;
  char			*cmd;
  int			argc;
  int			i;

  i = 0;
  cmd = c->actions->cmd;
  argc = nb_words(cmd);
  if (argc == 2)
    {
      tab = str_parser(cmd);
      while (gl_ressource_prend[i].id)
	{
	  if (my_strcmp(tab[1], gl_ressource_prend[i].name) == 0)
	    {
	      gl_ressource_prend[i].func(c, z);
	      rfc_graph_pgt(z, c, (gl_ressource_prend[i].id - 1));
	      return ;
	    }
	  i += 1;
	}
    }
}
