/*
** check_death.c for check death in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Wed Jul  6 23:44:58 2011 john mille
** Last update Fri Jul  8 19:18:04 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

int			check_ghost_death(t_zappy *z,
					 t_teams *t,
					 t_chars *c)
{
  struct timeval	tp;

  if (t->id > 2 && c->is_ghost == 1 && c->eat)
    {
      gettimeofday(&tp, NULL);
      if (c->invent && time_is_gone(&tp, c->eat))
	{
	  c->invent->nourriture -= 1;
	  calc_next_eat(z->map, &tp, c->eat);
	}
      if (c->invent && c->invent->nourriture == 0)
	{
	  rfc_graph_edi(z, c);
	  my_xwrite(c->s_chars, "mort\n", my_strlen("mort\n"));
	  t->chars = delete_char(t, c, 1);
	  return (1);
	}
    }
  return (0);
}

int			check_players_death(t_zappy *z,
					    t_teams *t,
					    t_chars *c)
{
  struct timeval	tp;

  if (t->id > 2 && c->is_ghost == 0 && c->eat)
    {
      gettimeofday(&tp, NULL);
      if (time_is_gone(&tp, c->eat))
	{
	  c->invent->nourriture -= 1;
	  calc_next_eat(z->map, &tp, c->eat);
	}
      if (c->invent && c->invent->nourriture == 0)
	{
	  rfc_graph_pdi(z, c);
	  my_xwrite(c->s_chars, "mort\n", my_strlen("mort\n"));
	  t->chars = delete_char(t, c, 1);
	  return (1);
	}
    }
  return (0);
}

void			check_deaths(t_zappy *z)
{
  t_teams		*t;
  t_chars		*c;

  t = z->teams;
  while (t)
    {
      c = t->chars;
      while (c)
	{
	  if (check_ghost_death(z, t, c) ||
	      check_players_death(z, t, c))
	    return ;
	  c = c->next;
	}
      t = t->next;
    }
}
