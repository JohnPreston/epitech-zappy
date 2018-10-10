/*
** loop.c for loop in /home/mille_j/zappy/serveur/src/networking
**
** Made by John Mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jun 14 07:27:23 2011 John Mille
** Last update Sun Jul 10 11:06:30 2011 john mille
*/

#include <sys/select.h>
#include <sys/types.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"
#include "my.h"

void			init_serv(t_zappy *zappy)
{
  FD_ZERO(&(zappy->net->_r));
  FD_SET(zappy->net->s_serv, &(zappy->net->_r));
  FD_ZERO(&(zappy->net->_w));
  FD_SET(zappy->net->s_serv, &(zappy->net->_w));
}

void			init_clients(t_zappy * zappy)
{
  t_teams		*team;
  t_chars	       	*chars;

  team = zappy->teams;
  while (team)
    {
      chars = team->chars;
      while (chars)
	{
	  FD_SET(chars->s_chars, &(zappy->net->_r));
	  chars = chars->next;
	}
      team = team->next;
    }
}

void			loop(t_zappy *zappy)
{
  zappy->net->s_max = zappy->net->s_serv + 1;
  zappy->net->_t.tv_usec = 1;
  while (42)
    {
      init_serv(zappy);
      init_clients(zappy);
      select(zappy->net->s_max,
	     &zappy->net->_r,
	     &zappy->net->_w,
	     NULL,
	     &zappy->net->_t);
      if (FD_ISSET(zappy->net->s_serv, &zappy->net->_r))
	add_client(zappy);
      check_clients(zappy);
      check_clients_tasks(zappy);
      check_incants(zappy);
      check_deaths(zappy);
    }
}
