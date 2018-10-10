/*
** rfc_graph_tna.c for tna in /home/mille_j//zappy/serveur/src/parsing
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jun 28 18:28:59 2011 john mille
** Last update Fri Jul  8 19:55:40 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			rfc_graph_tna(t_zappy *z,
				      __attribute__((unused))t_teams *t,
				      t_chars *c,
				      char *buff)
{
  t_teams		*team;
  int			argc;

  argc = nb_words(buff);
  if (argc == 1)
    {
      team = z->teams;
      while (team)
	{
	  if (team->id > 2)
	    {
	      if (dprintf(c->s_chars, "tna %s\n", team->name) == 0)
		{
		  c->s_chars = my_xclose(c->s_chars);
		  return ;
		}
	    }
	  team = team->next;
	}
    }
  rfc_graph_suc(c->s_chars);
}

void			rfc_graph_tna_serv(t_zappy *z)
{
  t_chars		*c;
  t_teams		*t_tmp;

  c = z->teams->next->chars;
  while (c)
    {
      t_tmp = z->teams->next->next->next;
      while (t_tmp)
	{
	  if ((dprintf(c->s_chars, "tna %s\n", t_tmp->name)) <= 0)
 	    z->teams->next->chars = delete_char(z->teams->next, c, 1);
	  t_tmp = t_tmp->next;
	}
      c = c->next;
    }
}
