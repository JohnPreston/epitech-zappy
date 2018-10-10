/*
** rfc_player_see_dirs_func.c for dir func in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jul  7 06:13:24 2011 john mille
** Last update Fri Jul  8 22:52:53 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

int			func(int a, int b)
{
  if (a >= b)
    return (a - b);
  else if (a < 0)
    return (b + a);
  return (a);
}

char			*see_north(t_zappy *z, t_chars *c, int x, int y)
{
  char			*see;
  char			*tmp;
  int			a;
  int			b;

  see = NULL;
  tmp = NULL;
  y = c->pos_y;
  while (y <= (c->pos_y + c->level))
    {
      x = c->pos_x - (y - c->pos_y);
      while (x <= (c->pos_x + (y - c->pos_y)))
	{
	  a = func(x, z->map->map_x);
	  b = func(y, z->map->map_y);
	  see = one_case(z, c, a, b, see);
	  if (!(x == (c->pos_x + (y - c->pos_y)) &&
		y == (c->pos_y + c->level)))
	    see = replace(see, ",");
	  tmp = see;
	  x += 1;
	}
      y += 1;
    }
  return (tmp);
}

char			*see_south(t_zappy *z, t_chars *c, int x, int y)
{
  char			*see;
  char			*tmp;
  int			a;
  int			b;

  see = NULL;
  tmp = NULL;
  y = c->pos_y;
  while (y >= (c->pos_y - c->level))
    {
      x = c->pos_x - (y - c->pos_y);
      while (x >= (c->pos_x + (y - c->pos_y)))
	{
	  a = func(x, z->map->map_x);
	  b = func(y, z->map->map_y);
	  see = one_case(z, c, a, b, see);
	  if (!(x == (c->pos_x + (y - c->pos_y)) &&
		y == (c->pos_y - c->level)))
	    see = replace(see, ",");
	  tmp = see;
	  x -= 1;
	}
      y -= 1;
    }
  return (tmp);
}

char			*see_west(t_zappy *z, t_chars *c, int x, int y)
{
  char			*see;
  char			*tmp;
  int			a;
  int			b;

  see = NULL;
  tmp = NULL;
  x = c->pos_x;
  while (x >= (c->pos_x - c->level))
    {
      y = c->pos_y + (x - c->pos_x);
      while (y <= (c->pos_y + (x - c->pos_x)))
	{
	  a = func(x, z->map->map_x);
	  b = func(y, z->map->map_y);
	  see = one_case(z, c, a, b, see);
	  if (!(y == (c->pos_y - (x - c->pos_x)) &&
		x == (c->pos_x - c->level)))
	    see = replace(see, ",");
	  tmp = see;
	  y += 1;
	}
      x -= 1;
    }
  return (tmp);
}

char			*see_east(t_zappy *z, t_chars *c, int x, int y)
{
  char			*see;
  char			*tmp;
  int			a;
  int			b;

  see = NULL;
  tmp = NULL;
  x = c->pos_x;
  while (x <= (c->pos_x + c->level))
    {
      y = c->pos_y + (x - c->pos_x);
      while (y >= (c->pos_y - (x - c->pos_x)))
	{
	  a = func(x, z->map->map_x);
	  b = func(y, z->map->map_y);
	  see = one_case(z, c, a, b, see);
	  if (!(y == (c->pos_y - (x - c->pos_x)) &&
		x == (c->pos_x + c->level)))
	    see = replace(see, ",");
	  tmp = see;
	  y -= 1;
	}
      x += 1;
    }
  return (tmp);
}
