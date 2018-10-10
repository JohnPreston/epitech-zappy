/*
** rfc_graph_bct.c for bct in /home/mille_j//zappy/serveur/src/parsing
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jun 28 15:53:12 2011 john mille
** Last update Sat Jul  9 11:52:48 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include "zappy.h"
#include "my.h"

static void		check_and_send(t_zappy *z, t_chars *c,
				       int i, int j)
{
  if (i > (z->map->map_x - 1) || j > (z->map->map_y - 1) ||
      i < 0 || j < 0)
    rfc_graph_suc(c->s_chars);
  else
    {
      if ((dprintf(c->s_chars, "bct %d %d %d %d %d %d %d %d %d\n",
		   i, j,
		   z->map->cases[i][j].nourriture,
		   z->map->cases[i][j].linemate,
		   z->map->cases[i][j].deraumere,
		   z->map->cases[i][j].sibur,
		   z->map->cases[i][j].mendiane,
		   z->map->cases[i][j].phiras,
		   z->map->cases[i][j].thystame)) <= 0)
	z->teams->next->chars = delete_char(z->teams->next, c, 1);
    }
}

void			rfc_graph_bct(t_zappy *z,
				      __attribute__((unused))t_teams *t,
				      t_chars *c,
				      char *buff)
{
  char			**argv;
  int			argc;
  int			_x;
  int			_y;

  if (buff)
    {
      argc = nb_words(buff);
      argv = str_parser(buff);
      if (argc != 3)
	my_xwrite(c->s_chars, "suc\n", 5);
      else
	{
	  _x = my_getnbr(argv[1]);
	  _y = my_getnbr(argv[2]);
	  check_and_send(z, c, _x, _y);
	}
    }
  else
    rfc_graph_suc(c->s_chars);
}

void			rfc_graph_bct_serv(t_zappy *z, int i, int j)
{
  t_chars		*c_tmp;

  c_tmp = z->teams->next->chars;
  while (c_tmp)
    {
      if ((dprintf(c_tmp->s_chars, "bct %d %d %d %d %d %d %d %d %d\n",
		   i, j,
		   z->map->cases[i][j].nourriture,
		   z->map->cases[i][j].linemate,
		   z->map->cases[i][j].deraumere,
		   z->map->cases[i][j].sibur,
		   z->map->cases[i][j].mendiane,
		   z->map->cases[i][j].phiras,
		   z->map->cases[i][j].thystame)) <= 0)
	z->teams->next->chars = delete_char(z->teams->next, c_tmp, 1);
      c_tmp = c_tmp->next;
    }
}
