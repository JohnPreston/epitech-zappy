/*
** rfc_player_broadcast.c for broadcast in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jul  7 14:17:30 2011 john mille
** Last update Fri Jul  8 23:11:32 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

static char		*make_msg(char *cmd)
{
  char			*msg;

  msg = NULL;
  if (cmd)
    msg = my_strdup3(cmd, ' ');
  return (msg);
}

void			deploy(t_zappy *z, t_chars *c, char *msg)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;
  int			dir;

  t_tmp = z->teams->next->next->next;
  while (t_tmp)
    {
      c_tmp = t_tmp->chars;
      while (c_tmp)
	{
	  if (c_tmp != c)
	    {
	      dir = get_direct(c->pos_x, c->pos_y, c_tmp->pos_x, c_tmp->pos_y);
	      dir = direct_4_char(dir, c_tmp->dir);
	      dprintf(c_tmp->s_chars, "message %d, %s\n", dir, msg);
	    }
	  c_tmp = c_tmp->next;
	}
      t_tmp = t_tmp->next;
    }
}

void			rfc_player_broadcast(t_zappy *z,
					     __attribute__((unused))t_teams *t,
					     t_chars *c)
{
  char			*cmd;
  char			*msg;
  int			argc;

  msg = NULL;
  cmd = c->actions->cmd;
  if ((argc = nb_words(cmd) > 1))
    {
      msg = make_msg(cmd);
      deploy(z, c, msg);
      rfc_graph_pbc(z, c, msg);
      my_xwrite(c->s_chars, "ok\n", 4);
      msg = my_xxfree(msg);
      return ;
    }
  else
    my_xwrite(c->s_chars, "ko\n", 5);
}
