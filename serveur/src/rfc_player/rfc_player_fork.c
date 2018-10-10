/*
** rfc_player_fork.c for fork in /home/mille_j//zappy/serveur/src/rfc_player
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Sun Jul  3 13:13:05 2011 john mille
** Last update Fri Jul  8 06:05:02 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <string.h>
#include "zappy.h"
#include "my.h"

t_chars			*create_egg(unsigned int id, unsigned int x, unsigned int y)
{
  t_chars		*egg;

  srand(time(NULL));
  egg = my_xmalloc(sizeof(*egg));
  egg->id = id;
  egg->level = 1;
  egg->pos_x = x;
  egg->pos_y = y;
  egg->dir = random_dir();
  egg->is_egg = 1;
  egg->is_ghost = 0;
  egg->actions = NULL;
  egg->invent = NULL;
  egg->eat = NULL;
  egg->next = NULL;
  return (egg);
}

void			rfc_player_exclose(t_zappy *z,
					   t_teams *t,
					   t_chars *c)
{
  c->is_egg = 0;
  c->is_ghost = 1;
  c->invent = my_xmalloc(sizeof(*c->invent));
  memset(c->invent, 0, sizeof(*c->invent));
  init_invent(c->invent);
  set_eat_time(z, c);
  rfc_graph_eht(z, c->id);
  t->max_members += 1;
}

void			rfc_player_fork(t_zappy *z,
					t_teams *t,
					t_chars *c)
{
  t_actions		*eclose;
  struct timeval	*time;
  t_chars		*egg;

  time = my_xmalloc(sizeof(*time));
  gettimeofday(time, NULL);
  egg = create_egg(z->id_client_ok, c->pos_x, c->pos_y);
  t->chars = add_char(t->chars, egg);
  eclose = create_action(&rfc_player_exclose, 600, time, z, t, egg, NULL);
  egg->actions = add_action(egg->actions, eclose);
  my_xwrite(c->s_chars, "ok\n", 4);
  rfc_graph_pfk(z, c);
  rfc_graph_enw(z, c, egg);
  z->id_client_ok += 1;
}
