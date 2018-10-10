/*
** check_can_incant.c for check can incant in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jul  7 20:37:06 2011 john mille
** Last update Fri Jul  8 10:51:35 2011 john mille
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

static t_elevation	gl_incant[] = {
  {1, 1, 1, 0, 0, 0, 0, 0},
  {2, 2, 1, 1, 1, 0, 0, 0},
  {3, 2, 2, 0, 1, 0, 2, 0},
  {4, 4, 1, 1, 2, 0, 1, 0},
  {5, 4, 1, 2, 1, 3, 0, 0},
  {6, 6, 1, 2, 3, 0, 1, 0},
  {7, 6, 2, 2, 2, 2, 2, 1},
  {0, 0, 0, 0, 0, 0, 0, 0},
};

int			check_nb_players(t_zappy *z, t_chars *c, int level)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;
  int			nb;

  nb = 1;
  t_tmp = z->teams->next->next->next;
  while (t_tmp)
    {
      c_tmp = t_tmp->chars;
      while (c_tmp)
	{
	  if (c_tmp != c && c_tmp->pos_x == c->pos_x &&
	      c->pos_y == c->pos_y &&
	      c_tmp->level == level)
	    nb += 1;
	  c_tmp = c_tmp->next;
	}
      t_tmp = t_tmp->next;
    }
  return (nb);
}

int			check_incant(t_zappy *z,
				       t_chars *c,
				       t_elevation *incant)
{
  if (z->map->cases[c->pos_x][c->pos_y].linemate == incant->nb_li &&
      z->map->cases[c->pos_x][c->pos_y].deraumere == incant->nb_de &&
      z->map->cases[c->pos_x][c->pos_y].sibur == incant->nb_si &&
      z->map->cases[c->pos_x][c->pos_y].mendiane == incant->nb_me &&
      z->map->cases[c->pos_x][c->pos_y].phiras == incant->nb_ph &&
      z->map->cases[c->pos_x][c->pos_y].thystame == incant->nb_th)
    {
      if (check_nb_players(z, c, (incant->id)) == incant->nb_pl)
	return (1);
    }
  return (0);
}

int			can_incant(t_zappy *z,
				   __attribute__((unused))t_teams *t,
				   t_chars *c)
{
  int			i;

  i = 0;
  while (gl_incant[i].id)
    {
      if (c->level == gl_incant[i].id)
	{
	  if (check_incant(z, c, &gl_incant[i]))
	    {
	      dprintf(c->s_chars, "elevation en cours\n");
	      return (1);
	    }
	  else
	    {
	      dprintf(c->s_chars, "ko\n");
	      return (0);
	    }
	}
      i += 1;
    }
  return (0);
}

void			check_incant_end(t_zappy *z,
					 __attribute__((unused))t_teams *t,
					 t_chars *incant,
					 __attribute__((unused))char *cmd)
{
  int			i;

  i = 0;
  while (gl_incant[i].id)
    {
      if (incant->level == gl_incant[i].id)
	{
	  if (check_incant(z, incant, &gl_incant[i]))
	    {
	      level_up(z, incant);
	      return ;
	    }
	  else
	    {
	      incant_failed(z, incant);
	      return ;
	    }
	}
      i += 1;
    }
}
