/*
** chars_specials.c for chas specials in /home/mille_j//zappy/serveur/tools
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jul  5 20:06:37 2011 john mille
** Last update Fri Jul  8 18:39:19 2011 john mille
*/

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include "zappy.h"
#include "my.h"

void				char_takes_ghost(t_zappy *z,
						 t_chars *c,
						 t_chars *ghost)
{
  struct timeval		now;

  gettimeofday(&now, NULL);
  ghost->is_egg = 0;
  ghost->is_ghost = 0;
  ghost->s_chars = c->s_chars;
  init_invent(ghost->invent);
  calc_next_eat(z->map, &now, ghost->eat);
  z->teams->chars = delete_char(z->teams, c, 0);
}

void				init_new_char(t_zappy *z,
					      t_chars *new,
					      t_chars *c)
{
  new->id = z->id_client_ok;
  new->s_chars = c->s_chars;
  new->dir = random_dir();
  new->pos_x = random_pos_x(z->map);
  new->pos_y = random_pos_y(z->map);
  new->level = 1;
  new->is_egg = 0;
  new->is_ghost = 0;
  new->invent = my_xmalloc(sizeof(*new->invent));
  init_invent(new->invent);
  set_eat_time(z, new);
  z->teams->chars = delete_char(z->teams, c, 0);
}
