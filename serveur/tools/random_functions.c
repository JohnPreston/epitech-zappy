/*
** random_dir.c for random dir in /home/mille_j//zappy/serveur
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Sun Jul  3 16:30:28 2011 john mille
** Last update Mon Jul  4 19:43:53 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "zappy.h"

int			random_dir()
{
  int			dir;

  srand(time(NULL) * getpid());
  dir = (rand() % (4) + 1);
  return (dir);
}

int			random_pos_x(t_map *map)
{
  int			dir;

  srand(time(NULL) * getpid());
  dir = (rand() % ((map->map_x - 1)));
  return (dir);
}

int			random_pos_y(t_map *map)
{
  int			dir;

  srand(time(NULL) * getpid());
  dir = (rand() % ((map->map_y - 1)));
  return (dir);
}
