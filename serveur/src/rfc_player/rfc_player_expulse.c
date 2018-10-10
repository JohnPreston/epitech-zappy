/*
** rfc_player_expulse.c for expulse in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Fri Jul  8 04:34:01 2011 john mille
** Last update Sun Jul 10 11:15:39 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			expulse(t_zappy *z, t_chars *expulsed, t_chars *c)
{
  if (c->dir == EAST && (expulsed->pos_x + 1) == z->map->map_x)
    expulsed->pos_x = 0;
  else if (c->dir == WEST && (expulsed->pos_x) == 0)
    expulsed->pos_x = z->map->map_x - 1;
  else if (c->dir == NORTH && (expulsed->pos_y + 1) == z->map->map_y)
    expulsed->pos_y = 0;
  else if (c->dir == SOUTH && (expulsed->pos_y) == 0)
    expulsed->pos_y = z->map->map_y - 1;
  else
    {
      if (c->dir == EAST)
        expulsed->pos_x += 1;
      else if (c->dir == WEST)
        expulsed->pos_x -= 1;
      else if (c->dir == NORTH)
        expulsed->pos_y += 1;
      else if (c->dir == SOUTH)
        expulsed->pos_y -= 1;
    }
}

void			give_dir(t_zappy *z,
				 t_teams *t,
				 t_chars *expulsed,
				 t_chars *c)
{
  int			dir;

  if (c->dir == NORTH)
    dir = BACK;
  else if (c->dir == SOUTH)
    dir = FRONT;
  else if (c->dir == WEST)
    dir = RIGHT;
  else if (c->dir == EAST)
    dir = LEFT;
  dir = dir - (expulsed->dir - 1);
  if (dir < 0)
    dir = -dir;
  if ((dprintf(expulsed->s_chars, "deplacement : %d\n", dir)) <= 0)
    t->chars = delete_char(t, expulsed, 1);
  rfc_graph_ppo_serv(z, expulsed);
}

static void		send_answer(t_teams *t, t_chars *c, int i)
{
  if (!i)
    {
      if ((dprintf(c->s_chars, "ko\n")) <= 0)
	t->chars = delete_char(t, c, 1);
    }
  else
    {
      if ((dprintf(c->s_chars, "ok\n")) <= 0)
	t->chars = delete_char(t, c, 1);
    }
}

void			rfc_player_expulse(t_zappy *z, t_teams *t, t_chars *c)
{
  t_teams               *t_tmp;
  t_chars               *c_tmp;
  int			i;

  i = 0;
  t_tmp = z->teams->next->next->next;
  while (t_tmp)
    {
      c_tmp = t_tmp->chars;
      while (c_tmp)
	{
	  if (c_tmp != c &&
	      c_tmp->pos_x == c->pos_x &&
	      c_tmp->pos_y == c->pos_y)
	    {
	      expulse(z, c_tmp, c);
	      give_dir(z, t, c_tmp, c);
	      i += 1;
	    }
	  c_tmp = c_tmp->next;
	}
      t_tmp = t_tmp->next;
    }
  send_answer(t, c, i);
}
