/*
** rfc_player_see_func_1.c for see func 1 in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jul  7 05:15:20 2011 john mille
** Last update Fri Jul  8 16:50:57 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

int			there_is_food(t_zappy *z,
				      __attribute__((unused))t_chars *c,
				      int x, int y)
{
  if (z->map->cases[x][y].nourriture)
    return (z->map->cases[x][y].nourriture);
  return (0);
}

int			there_is_linemate(t_zappy *z,
					  __attribute__((unused))t_chars *c,
					  int x, int y)
{
  if (z->map->cases[x][y].linemate)
    return (z->map->cases[x][y].linemate);
  return (0);
}

int			there_is_deraumere(t_zappy *z,
					   __attribute__((unused))t_chars *c,
					   int x, int y)
{
  if (z->map->cases[x][y].deraumere)
    return (z->map->cases[x][y].deraumere);
  return (0);
}

int			there_is_sibur(t_zappy *z,
				       __attribute__((unused))t_chars *c,
				       int x, int y)
{
  if (z->map->cases[x][y].sibur)
    return (z->map->cases[x][y].sibur);
  return (0);
}

int			there_is_mendiane(t_zappy *z,
					  __attribute__((unused))t_chars *c,
					  int x, int y)
{
  if (z->map->cases[x][y].mendiane)
    return (1);
  return (0);
}
