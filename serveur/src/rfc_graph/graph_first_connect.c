/*
** graph_first_connect.c for graph_first_connect in /home/mille_j//zappy/serveur/src/rfc_graph
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 05:14:34 2011 john mille
** Last update Fri Jul  8 06:43:28 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

static void		all_players(t_zappy *z, t_chars *graph)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;

  t_tmp = z->teams->next->next->next;
  while (t_tmp)
    {
      c_tmp = t_tmp->chars;
      while (c_tmp)
	{
	  if (c_tmp->is_egg == 0)
	    {
	      if ((dprintf(graph->s_chars, "pnw %d %d %d %d %d %s\n",
			   c_tmp->id, c_tmp->pos_x, c_tmp->pos_y,
			   c_tmp->dir, c_tmp->level, t_tmp->name)) <= 0)
		z->teams->next->chars = delete_char(z->teams->next, graph, 1);
	    }
	  c_tmp = c_tmp->next;
	}
      t_tmp = t_tmp->next;
    }
}

static void		all_eggs(t_zappy *z, t_chars *graph)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;

  t_tmp = z->teams->next->next->next;
  while (t_tmp)
    {
      c_tmp = t_tmp->chars;
      while (c_tmp)
	{
	  if (c_tmp->is_egg == 1)
	    {
	      if ((dprintf(graph->s_chars, "pnw %d %d %d %d %d %s\n",
			   c_tmp->id, c_tmp->pos_x, c_tmp->pos_y,
			   c_tmp->dir, c_tmp->level, t_tmp->name)) <= 0)
		z->teams->next->chars = delete_char(z->teams->next, graph, 1);
	    }
	  c_tmp = c_tmp->next;
	}
      t_tmp = t_tmp->next;
    }
}

static void		all_graphs(t_zappy *z)
{
  t_chars		*c_tmp;

  c_tmp = z->teams->next->chars;
  while (c_tmp)
    {
      all_players(z, c_tmp);
      all_eggs(z, c_tmp);
      c_tmp = c_tmp->next;
    }
}

void			graph_first_connect(t_zappy *z)
{
  rfc_graph_msz_serv(z);
  rfc_graph_sgt_serv(z);
  rfc_graph_mct_serv(z);
  rfc_graph_tna_serv(z);
  all_graphs(z);
  rfc_graph_pin_serv(z);
}
