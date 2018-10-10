/*
** create_incantation.c for  in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Fri Jul  8 00:33:27 2011 john mille
** Last update Fri Jul  8 09:57:39 2011 john mille
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

int			create_incant(t_zappy *z,
				      t_teams *t,
				      t_chars *c)
{
  t_chars		*new;
  t_actions		*incant_action;
  struct timeval	*time;

  time = my_xmalloc(sizeof(*time));
  gettimeofday(time, NULL);
  if (can_incant(z, t, c))
    {
      new = my_xmalloc(sizeof(*new));
      memset(new, 0, sizeof(*new));
      new->pos_x = c->pos_x;
      new->pos_y = c->pos_y;
      new->level = c->level;
      new->actions = NULL;
      new->eat = time;
      rfc_graph_pic(z, c);
      set_eat_time(z, new);
      incant_action = create_action(&check_incant_end, 300,
				    new->eat, z, z->teams->next->next, new, NULL);
      add_action(c->actions, incant_action);
      z->teams->next->next->chars = add_char(z->teams->next->next->chars, new);
      return (1);
    }
  return (0);
}
