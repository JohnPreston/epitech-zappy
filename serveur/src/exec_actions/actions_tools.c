/*
** actions_tools.c for actions tools in /home/mille_j//zappy/serveur/src/exec_actions
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Sat Jul  2 10:43:26 2011 john mille
** Last update Thu Jul  7 13:39:00 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

static void		calc_time(t_map *map, int coeff, struct timeval *time)
{
  unsigned int		to_add;
  unsigned int		sec_plus;
  unsigned int		usec_plus;

  to_add = 0;
  to_add = (coeff * 1000000) / map->time;
  sec_plus = to_add / 1000000;
  usec_plus = to_add % 1000000;
  time->tv_sec += sec_plus;
  time->tv_usec += to_add;
  if (time->tv_usec > 1000000)
    {
      time->tv_usec -= 1000000;
      time->tv_sec += 1;
    }
}

t_actions		*create_action(void *action,
				       int time_coeff,
				       struct timeval *time,
				       t_zappy *z,
				       t_teams *t,
				       t_chars *c,
				       char *cmd)
{
  struct timeval	*new_time;
  t_actions		*new;

  new_time = my_xmalloc(sizeof(*new_time));
  new = my_xmalloc(sizeof(*new));
  new->last = new;
  new->next = NULL;
  new->z = z;
  new->t = t;
  new->c = c;
  new->cmd = my_strdup(cmd);
  new->nb_actions = 0;
  new->time = new_time;
  new->time->tv_sec = time->tv_sec;
  new->time->tv_usec = time->tv_usec;
  calc_time(z->map, time_coeff, new->time);
  new->res = NULL;
  new->func = action;
  return (new);
}

t_actions		*add_action(t_actions *actions, t_actions *new)
{
  t_actions		*head;
  t_actions		*last;

  if (actions)
    {
      head = actions;
      last = head->last;
      last->next = new;
      head->last = new;
      head->nb_actions += 1;
    }
  else
    head = new;
  return (head);
}

t_actions		*depop_action(t_actions *actions)
{
  t_actions		*n;

  if (actions)
    {
      n = actions->next;
      actions->time = my_xfree(actions->time);
      actions->cmd = my_xxfree(actions->cmd);
      actions = my_xfree(actions);
      if (n)
	n->nb_actions -= 1;
      return (n);
    }
  return (NULL);
}
