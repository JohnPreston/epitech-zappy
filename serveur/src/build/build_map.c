/*
** init_map.c for init_map in /home/bruyer_b//zappy/serveur/src/cmd_line
**
** Made by benoit bruyere
** Login   <bruyer_b@epitech.net>
**
** Started on  Wed Jun 22 13:02:32 2011 benoit bruyere
** Last update Fri Jul  8 08:25:48 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "zappy.h"
#include "my.h"

int			set_ressource()
{
  int			tmp;

  tmp = 0;
  tmp = (rand() % (100) + 1);
  if (tmp >= 70)
    return (rand() % (3) + 1);
  return (0);
}

void			init_ressource(t_case *Case)
{
  Case->nourriture = set_ressource();
  Case->linemate = set_ressource();
  Case->deraumere = set_ressource();
  Case->sibur = set_ressource();
  Case->mendiane = set_ressource();
  Case->phiras = set_ressource();
  Case->thystame = set_ressource();
}

t_case			**alloc_case(t_case **Case, t_zappy *zappy)
{
  int			x;
  int			y;

  x = 0;
  y = 0;
  Case = malloc(zappy->map->map_x * sizeof(t_case));
  while (x < zappy->map->map_x)
  {
    Case[x] = malloc(zappy->map->map_y * sizeof(t_case));
    x++;
  }
  return (Case);
}

void			init_case(t_zappy *zappy, t_case **Case)
{
  int			x;
  int			y;

  y = 0;
  x = 0;
  srand(time(NULL));
  Case = alloc_case(Case, zappy);
  while (y < zappy->map->map_y)
  {
    x = 0;
    while (x < zappy->map->map_x)
    {
      Case[x][y].x = x;
      Case[x][y].y = y;
      init_ressource(&Case[x][y]);
      x++;
    }
    y++;
  }
  zappy->map->cases = Case;
}
