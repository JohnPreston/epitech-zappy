/*
** init_invent.c for init invent in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Mon Jul  4 15:15:46 2011 john mille
** Last update Tue Jul  5 02:42:48 2011 john mille
*/

#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void				calc_next_eat(t_map *map, struct timeval *now,
					      struct timeval *time)
{
  unsigned int			to_add;
  unsigned int			sec_plus;
  unsigned int			usec_plus;

  to_add = 0;
  to_add = (126 * 1000000) / map->time;
  sec_plus = to_add / 1000000;
  usec_plus = to_add % 1000000;
  time->tv_sec = now->tv_sec + sec_plus;
  time->tv_usec = now->tv_usec + usec_plus;
  if (time->tv_usec > 1000000)
    {
      time->tv_usec -= 1000000;
      time->tv_sec += 1;
    }
}

void				set_eat_time(t_zappy *z, t_chars *new)
{
  struct timeval		time;

  if (new->invent)
    {
      gettimeofday(&time, NULL);
      new->eat = my_xmalloc(sizeof(*new->eat));
      memset(new->eat, 0, sizeof(*new->eat));
      calc_next_eat(z->map, &time, new->eat);
    }
}

void				init_invent(t_invent *i)
{
  i->nourriture = 10;
  i->linemate = 0;
  i->deraumere = 0;
  i->sibur = 0;
  i->mendiane = 0;
  i->phiras = 0;
  i->thystame = 0;
}
