/*
** rfc_graph_mct.c for mct in /home/mille_j//zappy/serveur/src/parsing
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jun 28 17:40:57 2011 john mille
** Last update Fri Jul  8 19:53:40 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

static void		check_and_send(t_zappy *z, t_chars *c)
{
  int			i;
  int			j;

  i = 0;
  while (i <= (z->map->map_x - 1))
    {
      j = 0;
      while (j <= (z->map->map_y - 1))
	{
	  if ((dprintf(c->s_chars, "bct %d %d %d %d %d %d %d %d %d\n",
		       i, j, z->map->cases[i][j].nourriture,
		       z->map->cases[i][j].linemate,
		       z->map->cases[i][j].deraumere,
		       z->map->cases[i][j].sibur,
		       z->map->cases[i][j].mendiane,
		       z->map->cases[i][j].phiras,
		       z->map->cases[i][j].thystame)) <= 0)
	    z->teams->next->chars = delete_char(z->teams->next, c, 1);
	    j += 1;
	}
      i += 1;
    }
}

void			rfc_graph_mct(t_zappy *z,
				      __attribute__((unused))t_teams *t,
				      t_chars *c,
				      char *buff)
{
  int			argc;

  if (buff)
    {
      argc = nb_words(buff);
      if (argc == 1)
	check_and_send(z, c);
      else
	rfc_graph_suc(c->s_chars);
    }
}

void			rfc_graph_mct_serv(t_zappy *z)
{
  t_teams		*t;
  t_chars		*c_tmp;

  t = z->teams;
  t = t->next;
  c_tmp = t->chars;
  while (c_tmp)
    {
      check_and_send(z, c_tmp);
      c_tmp = c_tmp->next;
    }
}
