/*
** check_team.c for check team in /home/mille_j//zappy/serveur/src/networking
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 23 01:34:28 2011 john mille
** Last update Fri Jul  8 23:44:58 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

t_teams			*team_name_ok(t_teams *team, char *name)
{
  t_teams		*t;

  t = team;
  while (t)
    {
      if (my_strcmp(t->name, name) == 0)
	return (t);
      t = t->next;
    }
  return (NULL);
}

int			team_capacity_ok(t_teams *t)
{
  if (t->id <= 2)
    {
      t->max_members += 1;
      t->nb_members += 1;
      return (1);
    }
  else if ((t->id > 2) && (t->nb_members < t->max_members))
    return (1);
  return (0);
}

void			put_char_in_team(t_zappy *z,
					 t_teams *t,
					 t_chars *c)
{
  t_chars		*new;

  new = my_xmalloc(sizeof(*new));
  init_new_char(z, new, c);
  t->chars = add_char(t->chars, new);
  t->nb_members += 1;
  z->id_client_ok += 1;
  z->net->s_max += 1;
  send_datas(z, t, new);
}

int			control_team_ghosts(t_zappy *z,
					    t_teams *t,
					    t_chars *c)
{
  t_chars		*c_tmp;

  c_tmp = t->chars;
  while (c_tmp)
    {
      if (c_tmp->is_ghost == 1)
	{
	  char_takes_ghost(z, c, c_tmp);
	  rfc_graph_ebo(z, c_tmp->id);
	  rfc_graph_pnw(z, t, c_tmp);
	  if ((dprintf(c_tmp->s_chars, "%d\n%d %d\n", c_tmp->id,
		       z->map->map_x, z->map->map_y)) <= 0)
	    t->chars = delete_char(t, c_tmp, 1);
	  return (1);
	}
      c_tmp = c_tmp->next;
    }
  return (0);
}

void			check_team(t_zappy *z,
				   t_chars *c,
				   char *t_name)
{
  t_teams		*t;

  t = team_name_ok(z->teams,  t_name);
  if (t)
    {
      if (team_capacity_ok(t))
	{
	  if (control_team_ghosts(z, t, c))
	    return ;
	  else
	    {
	      put_char_in_team(z, t, c);
	      return ;
	    }
	}
      else
	{
	  my_xwrite(z->net->s_client, "ko\n", 4);
	  z->teams->chars = delete_char(z->teams, c, 1);
	  return ;
	}
    }
  my_xwrite(z->net->s_client, "ko\n", 4);
  z->teams->chars = delete_char(z->teams, c, 1);
}
