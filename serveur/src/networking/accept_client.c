/*
** accept_client_connection.c for accept connection client in /home/mille_j//zappy/serveur/src/networking
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Sun Jul  3 16:13:51 2011 john mille
** Last update Tue Jul  5 19:31:36 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

int			send_welcome(SOCKET cli)
{
  if ((my_xwrite(cli, WELCOME, my_strlen(WELCOME))) <= 0)
    {
      cli = my_xclose(cli);
      return (0);
    }
  return (1);
}

void			add_client_on_waitin(t_zappy *z)
{
  t_chars		*new;

  new = create_char(z->id_client, z->net->s_client);
  z->teams->chars = add_char(z->teams->chars, new);
  z->id_client += 1;
  z->net->s_max += 1;
}

void			add_client(t_zappy *z)
{
  if ((z->net->s_client = my_xaccept(z->net->s_serv,
				     (SOCKADDR *)&z->net->cin_client,
				     &z->net->cin_size)) > 0)
    {
      if (send_welcome(z->net->s_client))
	add_client_on_waitin(z);
    }
}
