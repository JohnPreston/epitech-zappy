/*
** rfc_graph_sst.c for sst in /home/mille_j//zappy/serveur/src/parsing
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 04:27:56 2011 john mille
** Last update Thu Jul  7 19:06:36 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			rfc_graph_sst(t_zappy *z,
				      __attribute__((unused))t_teams *t,
				      t_chars *c,
				      char *buff)
{
  char			**argv;
  int			argc;

  if (buff)
    {
      argc = nb_words(buff);
      if (argc == 2)
	{
	  argv = str_parser(buff);
	  if (my_strisnum(argv[1]))
	    {
	      z->map->time = my_getnbr(argv[1]);
	      z->map->time_unit = 1 / z->map->time;
	      rfc_graph_sgt(z, t, c, buff);
	    }
	  else
	    rfc_graph_suc(c->s_chars);
	}
      else
	rfc_graph_suc(c->s_chars);
    }
  else
    rfc_graph_suc(c->s_chars);
}
