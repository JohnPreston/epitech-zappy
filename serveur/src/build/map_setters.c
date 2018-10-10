/*
** build_map.c for build map for zappy in /home/mille_j/zappy/serveur/src/cmd_line
**
** Made by John Mille
** Login   <mille_j@epitech.net>
**
** Started on  Sun Jun 12 06:02:18 2011 John Mille
** Last update Thu Jul  7 19:24:56 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "zappy.h"
#include "my.h"

void			set_map_x(t_zappy *zappy, char **argv, int i)
{
  zappy->map->map_x = my_getnbr(argv[i + 1]);
}

void			set_map_y(t_zappy *zappy, char **argv, int i)
{
  zappy->map->map_y = my_getnbr(argv[i + 1]);
}

void			set_map_time_unit(t_zappy *z, char **argv, int i)
{
  z->map->time = my_getnbr(argv[i + 1]);
  z->map->time_unit = (1 / (my_getnbr(argv[i + 1])));
}
