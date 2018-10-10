/*
** parsing.c for parsing in /home/mille_j//zappy/serveur/src/parsing
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 23 20:42:20 2011 john mille
** Last update Thu Jul  7 19:19:40 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

typedef struct		s_rfc_graph
{
  int			id;
  int			nb_args;
  char			*name;
  char			*flag;
  void			(*func)(t_zappy *zappy,
				t_teams *teams,
				t_chars *chars,
				char *buff);
}			t_rfc_graph;

t_rfc_graph			gl_rfc_graph[] = {
  {1, 1, "Map Size", "msz", rfc_graph_msz},
  {2, 3, "One case content", "bct", rfc_graph_bct},
  {3, 1, "Whole map", "mct", rfc_graph_mct},
  {4, 1, "nom des equipes", "tna", rfc_graph_tna},
  {5, 2, "pl pos", "ppo", rfc_graph_ppo},
  {6, 2, "pl lvl", "plv", rfc_graph_plv},
  {7, 2, "pl inv", "pin", rfc_graph_pin},
  {8, 1, "time unit", "sgt", rfc_graph_sgt},
  {9, 2, "set time unit", "sst", rfc_graph_sst},
  {0, 0, NULL, NULL, NULL},
};

void			parser_rfc_graph(t_zappy *zappy,
					 t_teams *teams,
					 t_chars *chars,
					 char *buff)
{
  char			**argv;
  int			argc;
  int			i;

  i = 0;
  argc = nb_words(buff);
  argv = str_parser(buff);
  while (gl_rfc_graph[i].id)
    {
      if ((my_strcmp(argv[0], gl_rfc_graph[i].flag) == 0) &&
	  gl_rfc_graph[i].func)
	{
	  gl_rfc_graph[i].func(zappy, teams, chars, buff);
	  argv = my_xfree_tab(argv);
	  return ;
	}
      i += 1;
    }
  if (chars->s_chars > 0)
    rfc_graph_suc(chars->s_chars);
}
