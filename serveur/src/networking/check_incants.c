/*
** check_incants.c for check incants in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jul  7 23:43:31 2011 john mille
** Last update Fri Jul  8 00:27:59 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			check_incants_time(t_chars *c)
{
  struct timeval	tp;
  int			i;

  i = 0;
  gettimeofday(&tp, NULL);
  if (time_is_gone(&tp, c->actions->time))
    {
      c->actions->func(c->actions->z, c->actions->t,
		       c->actions->c, c->actions->cmd);
      c->actions = depop_action(c->actions);
    }
}

void			check_incants(t_zappy * zappy)
{
  t_teams		*team;
  t_chars	       	*chars;

  team = zappy->teams->next->next;
  chars = team->chars;
  while (chars)
    {
      if (chars->actions)
	check_incants_time(chars);
      chars = chars->next;
    }
}
