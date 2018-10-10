/*
** rfc_player_parsing.c for rfc player in /home/mille_j//zappy/serveur/src/rfc_player
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 18:12:04 2011 john mille
** Last update Sat Jul  9 01:28:10 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>
#include "zappy.h"
#include "my.h"

typedef struct			s_player
{
  int				id;
  int				time_coeff;
  char				*flag;
  void				(*func)(t_zappy *z, t_teams *t, t_chars *c);
  int				(*check)(t_zappy *z, t_teams *t, t_chars *c);
}				t_player;

static t_player			gl_player[] = {
  {1, 7, "avance", rfc_player_avance, NULL},
  {2, 7, "droite", rfc_player_right, NULL},
  {3, 7, "gauche", rfc_player_left, NULL},
  {4, 7, "voir", rfc_player_see, NULL},
  {5, 1, "inventaire", rfc_player_invent, NULL},
  {6, 7, "prend", rfc_player_prend, NULL},
  {7, 7, "pose", rfc_player_pose, NULL},
  {8, 7, "expulse", rfc_player_expulse, NULL},
  {9, 7, "broadcast", rfc_player_broadcast, NULL},
  {10, 300, "incantation", rfc_player_incantation, create_incant},
  {11, 42, "fork", rfc_player_fork, NULL},
  {12, 0, "connect_nbr", rfc_player_connect_nbr, NULL},
  {13, 0, "-\n", NULL, NULL},
  {0, 0, NULL, NULL, NULL},
};

void				do_action(t_zappy *z, t_teams *t,
					  void *func,
					  int coeff,
					  t_chars *c,
					  struct timeval *time,
					  char *cmd)
{
  t_actions			*action;

  if (!c->actions)
    {
      action = create_action(func, coeff, time, z, t, c, cmd);
      c->actions = add_action(c->actions, action);
    }
  else
    {
      if (c->actions->nb_actions <= 10)
	{
	  if (c->actions->last)
	    action = create_action(func, coeff,
				   c->actions->last->time, z, t, c, cmd);
	  else
	    action = create_action(func, coeff, c->actions->time, z, t, c, cmd);
	  c->actions = add_action(c->actions, action);
	}
      else
	my_xwrite(c->s_chars, "ko\n", 4);
    }
}

int				check_func(t_zappy *z, t_teams *t,
					   struct timeval *time,
					   t_chars *c, char *cmd, int i)
{
  if (my_strncmp(gl_player[i].flag, cmd,
		 my_strlen(gl_player[i].flag)) == 0 &&
      gl_player[i].func &&
      gl_player[i].id != 10)
    {
      do_action(z, t, gl_player[i].func,
		gl_player[i].time_coeff, c, time, cmd);
      return (1);
    }
  return (0);
}

int				check_func_2(t_zappy *z, t_teams *t,
					     struct timeval *time,
					     t_chars *c, char *cmd, int i)
{
  if (my_strncmp(gl_player[i].flag, cmd,
		 my_strlen(gl_player[i].flag)) == 0 &&
      gl_player[i].id == 10 &&
      gl_player[i].check &&
      gl_player[i].check(z, t, c))
    {
      do_action(z, t, gl_player[i].func,
		gl_player[i].time_coeff, c, time, cmd);
      return (1);
    }
  return (0);
}

void				rfc_player_parsing(t_zappy *z, t_teams *t,
						   t_chars *c, char *cmd)
{
  struct timeval		*time;
  int				i;

  i = 0;
  time = my_xmalloc(sizeof(*time));
  gettimeofday(time, NULL);
  while (gl_player[i].id)
    {
      if (check_func(z, t, time, c, cmd, i))
	return ;
      else if (check_func_2(z, t, time, c, cmd, i))
	return ;
      i += 1;
    }
  my_xwrite(c->s_chars, "ko\n", 4);
}
