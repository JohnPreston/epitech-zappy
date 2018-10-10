/*
** rfc_graph_map_size.c for map size in /home/mille_j//zappy/serveur/src/parsing
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jun 28 14:22:42 2011 john mille
** Last update Fri Jul  8 06:35:45 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			rfc_graph_msz(t_zappy *zappy,
				      __attribute__((unused))t_teams *team,
				      t_chars *chars,
				     char *buff)
{
  int			argc;

  if (buff)
    {
      argc = nb_words(buff);
      if (argc == 1)
	dprintf(chars->s_chars, "msz %d %d\n",
		zappy->map->map_x,
		zappy->map->map_y);
    }
}

void			rfc_graph_msz_serv(t_zappy *z)
{
  t_chars		*c_tmp;

  c_tmp = z->teams->next->chars;
  while (c_tmp)
    {
      if ((dprintf(c_tmp->s_chars, "msz %d %d\n",
		   z->map->map_x, z->map->map_y)) <= 0)
	z->teams->next->chars = delete_char(z->teams->next, c_tmp, 1);
      c_tmp = c_tmp->next;
    }
}
