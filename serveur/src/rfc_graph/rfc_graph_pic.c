/*
** rfc_graph_pic.c for pex.c in /home/mille_j//zappy/serveur/src/rfc_graph
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 08:28:10 2011 john mille
** Last update Fri Jul  8 18:17:58 2011 john mille
*/

#include <stdio.h>
#include "zappy.h"

static void		players_on_case(t_zappy *z, t_chars *graph, t_chars *c)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;
  int			i;

  i = 0;
  t_tmp = z->teams->next->next->next;
  while (t_tmp)
    {
      c_tmp = t_tmp->chars;
      while (c_tmp)
	{
	  if (c != c_tmp && c_tmp->pos_x == c->pos_x &&
	      c_tmp->pos_y == c->pos_y && i == 0)
	    {
	      dprintf(graph->s_chars, "%d", c_tmp->id);
	      i += 1;
	    }
	  else if (c != c_tmp && c_tmp->pos_x == c->pos_x &&
		   c_tmp->pos_y == c->pos_y && i == 1)
	    dprintf(graph->s_chars, " %d", c_tmp->id);
	  c_tmp = c_tmp->next;
	}
      t_tmp = t_tmp->next;
    }
  dprintf(graph->s_chars, "\n");
}

void			rfc_graph_pic(t_zappy *z, t_chars *c)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;
  int			pass;

  pass = 0;
  t_tmp = z->teams->next;
  c_tmp = t_tmp->chars;
  while (c_tmp)
    {
      if (pass == 0)
	{
	  dprintf(c_tmp->s_chars, "pic %d ", c->id);
	  pass = 1;
	}
      else
	players_on_case(z, c_tmp, c);
      c_tmp = c_tmp->next;
    }
}
