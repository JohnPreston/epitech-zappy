/*
** build.c for build in /home/mille_j/zappy/serveur/src/cmd_line
**
** Made by John Mille
** Login   <mille_j@epitech.net>
**
** Started on  Sat Jun 11 15:27:00 2011 John Mille
** Last update Sun Jul  3 15:29:08 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "zappy.h"
#include "my.h"

t_options			gl_options[] = {
  {1, "-p", set_net_port},
  {2, "-x", set_map_x},
  {3, "-y", set_map_y},
  {5, "-c", set_max_clients},
  {4, "-n", build_teams},
  {6, "-t", set_map_time_unit},
  {0, NULL, NULL}
};

void				build_from_cmd(char **argv,
					       t_zappy *zappy)
{
  int				i[2];

  i[0] = 0;
  i[1] = 0;
  while (gl_options[i[1]].flag)
    {
      i[0] = 0;
      while (argv[i[0]])
	{
	  if (gl_options[i[1]].func &&
	      my_strcmp(argv[i[0]], gl_options[i[1]].flag) == 0)
	    gl_options[i[1]].func(zappy, argv, i[0]);
	  i[0] += 1;
	}
      i[1] += 1;
    }
}

int				build(int argc, char **argv, t_zappy *zappy)
{
  t_map				*map;
  t_net				*net;
  t_case			**Case;

  if (check_cmd_line(argc, argv))
    {
      map = my_xmalloc(sizeof(*map));
      memset(map, 0, sizeof(*map));
      net = my_xmalloc(sizeof(*net));
      memset(net, 0, sizeof(*net));
      Case = my_xmalloc(sizeof(Case));
      memset(Case, 0, sizeof(*Case));
      zappy->map = map;
      zappy->net = net;
      build_from_cmd(argv, zappy);
      init_case(zappy, Case);
      return (1);
    }
  return (0);
}
