/*
** rfc_graph_ppo.c for ppo in /home/mille_j//zappy/serveur/src/parsing
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Wed Jun 29 21:48:49 2011 john mille
** Last update Fri Jul  8 00:58:18 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

static int		get_player_id(char *buff)
{
  char			**argv;
  int			argc;
  int			player_id;

  argv = str_parser(buff);
  argc = nb_words(buff);
  if (argc != 2)
    return (-1);
  player_id = my_getnbr(argv[1]);
  if (player_id < 0)
    return (-1);
  return (player_id);
}

void			rfc_graph_plv(t_zappy *z,
				      __attribute__((unused))t_teams *t,
				      t_chars *c,
				      char *buff)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;
  int			p_id;

  p_id = get_player_id(buff);
  if (p_id >= 0)
    {
      t_tmp = z->teams;
      while (t_tmp)
	{
	  c_tmp = t_tmp->chars;
	  while (c_tmp)
	    {
	      if (c_tmp->id == p_id)
		{
		  dprintf(c->s_chars, "plv %d %d\n", c_tmp->id, c_tmp->level);
		  return ;
		}
	      c_tmp = c_tmp->next;
	    }
	  t_tmp = t_tmp->next;
	}
    }
}

void			rfc_graph_plv_serv(t_zappy *z, t_chars *c)
{
  t_chars		*c_tmp;

  c_tmp = z->teams->next->chars;
  while (c_tmp)
    {
      dprintf(c_tmp->s_chars, "plv %d %d\n", c->id, c->level);
      c_tmp = c_tmp->next;
    }
}
