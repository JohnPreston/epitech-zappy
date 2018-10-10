/*
** rfc_player_see.c for see in /home/mille_j//zappy/serveur/src/rfc_player
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jul  5 05:13:11 2011 john mille
** Last update Fri Jul  8 17:20:30 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

static t_map_		gl_map_[] = {
  {1, "joueur", there_is_player},
  {2, "nourriture", there_is_food},
  {3, "linemate", there_is_linemate},
  {4, "deraumere", there_is_deraumere},
  {5, "sibur", there_is_sibur},
  {6, "mendiane", there_is_mendiane},
  {7, "phiras", there_is_phiras},
  {8, "thystame", there_is_thystame},
  {0, NULL, NULL}
};

char		*concat_objs(int nb, char *name, char *see)
{
  int		i;

  i = 0;
  while (i < nb)
    {
      see = replace(see, name);
      if (i != nb - 1)
	see = replace(see, " ");
      i += 1;
    }
  return (see);
}

char			*one_case(t_zappy *z, t_chars *c, int x,
				  int y, char *see)
{
  static int		pass = 0;
  int			i;
  int			j;
  int			nb;

  i = 0;
  j = 0;
  nb = 0;
  if (pass)
    see = replace(see, " ");
  while (gl_map_[i].id)
    {
      if ((gl_map_[i].func && (nb = gl_map_[i].func(z, c, x, y))) > 0)
	{
	  if (j)
	    see = replace(see, " ");
	  see = concat_objs(nb, gl_map_[i].name, see);
	  j += 1;
	}
      i += 1;
    }
  if (j)
    pass += 1;
  return (see);
}

void			rfc_player_see(t_zappy *z,
				       t_teams *t,
				       t_chars *c)
{
  char			*see;
  char			*tmp;
  int			x;
  int			y;

  x = 0;
  y = 0;
  see = NULL;
  tmp = my_strcat(see, "{");
  if (c->dir == NORTH)
    see = see_north(z, c, x, y);
  else if (c->dir == SOUTH)
    see = see_south(z, c, x, y);
  else if (c->dir == EAST)
    see = see_east(z, c, x, y);
  else if (c->dir == WEST)
    see = see_west(z, c, x, y);
  tmp = replace(tmp, see);
  tmp = replace(tmp, "}\n");
  if ((my_xwrite(c->s_chars, tmp, my_strlen(tmp))) <= 0)
    t->chars = delete_char(t, c, 1);
}
