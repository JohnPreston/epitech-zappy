/*
** check_clients.c for check clients in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jul  5 00:46:30 2011 john mille
** Last update Thu Jul  7 23:44:13 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			check_clients(t_zappy *zappy)
{
  t_teams		*team;
  t_chars	       	*chars;

  team = zappy->teams;
  while (team)
    {
      chars = team->chars;
      while (chars)
	{
	  if (FD_ISSET(chars->s_chars, &zappy->net->_r))
	    {
	      gere_client(zappy, team, chars);
	      return ;
	    }
	  chars = chars->next;
	}
      team = team->next;
    }
}

void			dump_actions_list(t_chars *c)
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

void			check_clients_tasks(t_zappy * zappy)
{
  t_teams		*team;
  t_chars	       	*chars;

  team = zappy->teams;
  while (team)
    {
      chars = team->chars;
      while (chars)
	{
	  if (chars->actions)
	    dump_actions_list(chars);
	  chars = chars->next;
	}
      team = team->next;
    }
}
