/*
** gere_clients.c for gere clients in /home/mille_j//zappy/serveur/src/networking
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 23 01:38:04 2011 john mille
** Last update Fri Jul  8 18:29:15 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			player_deco(t_teams *t, t_chars *c)
{
  if (t->id <= 1)
    t->chars = delete_char(t, c, 1);
  else if (t->id > 2)
    {
      c->is_ghost = 1;
      c->s_chars = my_xclose(c->s_chars);
      c->actions = NULL;
    }
}

void			gere_client(t_zappy *zappy,
				    t_teams *teams,
				    t_chars *chars)
{
  char			buff[1024];
  int			nb;

  nb = 0;
  my_memset(buff, '\0', 1024);
  if ((nb = my_xread(chars->s_chars, buff, 1024)) <= 0)
    player_deco(teams, chars);
  else
    {
      if (nb > 0 && teams->id == 0)
	{
	  buff[my_strlen(buff) - 1] = '\0';
	  check_team(zappy, chars, buff);
	}
      else if (nb > 0)
	{
	  buff[my_strlen(buff) - 1] = '\0';
	  if (teams->id == 1 && chars->s_chars > 0)
	    parser_rfc_graph(zappy, teams, chars, buff);
	  else if (teams->id > 2)
	    rfc_player_parsing(zappy, teams, chars, buff);
	}
    }
}
