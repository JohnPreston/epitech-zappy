/*
** rfc_graph_ppo.c for ppo in /home/mille_j//zappy/serveur/src/parsing
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Wed Jun 29 21:48:49 2011 john mille
** Last update Sun Jul 10 11:09:38 2011 john mille
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

void			print_inventory(t_teams *t, t_chars *c, t_chars *c_tmp)
{
  if ((dprintf(c->s_chars, "pin %d %d %d %d %d %d %d %d %d %d\n",
	       c_tmp->id, c_tmp->pos_x, c_tmp->pos_y, c_tmp->invent->nourriture,
	       c_tmp->invent->linemate, c_tmp->invent->deraumere,
	       c_tmp->invent->sibur, c_tmp->invent->mendiane,
	       c_tmp->invent->phiras, c_tmp->invent->thystame)) <= 0)
    t->chars = delete_char(t, c, 1);

    }

void			rfc_graph_pin(t_zappy *z,
				      __attribute__((unused))t_teams *t,
				      t_chars *c,
				      char *buff)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;
  int			p_id;

  if ((p_id = get_player_id(buff)) >= 0)
    {
      t_tmp = z->teams->next;
      c_tmp = t_tmp->chars;
      while (c_tmp)
	{
	  if (c_tmp->id == p_id)
	    {
	      print_inventory(t_tmp, c, c_tmp);
	      return ;
	    }
	  c_tmp = c_tmp->next;
	}
    }
  else
    my_xwrite(c->s_chars, "suc\n", 4);
}

static void		all_players(t_zappy *z, t_chars *graph)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;

  t_tmp = z->teams->next->next->next;
  while (t_tmp)
    {
      c_tmp = t_tmp->chars;
      while (c_tmp)
	{
	  if (c_tmp->is_egg == 0)
	    {
	      if (dprintf(graph->s_chars, "pin %d %d %d %d %d %d %d %d %d %d\n",
			  c_tmp->id, c_tmp->pos_x, c_tmp->pos_y,
			  c_tmp->invent->nourriture, c_tmp->invent->linemate,
			  c_tmp->invent->deraumere, c_tmp->invent->sibur,
			  c_tmp->invent->mendiane, c_tmp->invent->phiras,
			  c_tmp->invent->thystame) <= 0)
		t_tmp->chars = delete_char(t_tmp, graph, 1);
	    }
	  c_tmp = c_tmp->next;
	}
      t_tmp = t_tmp->next;
    }
}
void			rfc_graph_pin_serv(t_zappy *z)
{
  t_teams		*t;
  t_chars		*c;

  t = z->teams->next;
  c = t->chars;
  while (c)
    {
      all_players(z, c);
      c = c->next;
    }
}
