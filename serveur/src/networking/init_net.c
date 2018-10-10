/*
** init_net.c for init net in /home/mille_j/zappy/serveur/src/networking
**
** Made by John Mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jun 14 02:51:33 2011 John Mille
** Last update Wed Jun 22 16:09:37 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

int			init_sockets(t_zappy *zappy)
{
  int			errors[2];
  zappy->net->sin_serv.sin_addr.s_addr = htonl(INADDR_ANY);
  zappy->net->sin_serv.sin_port = htons(zappy->net->port);
  zappy->net->sin_serv.sin_family = AF_INET;
  zappy->net->opt = 1;
  zappy->net->sin_size = sizeof(zappy->net->sin_serv);
  errors[0] = my_xsetsockopt(zappy->net->s_serv, SOL_SOCKET, SO_REUSEADDR,
			     &zappy->net->opt, sizeof(zappy->net->opt));
  zappy->net->cin_client.sin_addr.s_addr = htonl(INADDR_ANY);
  zappy->net->cin_client.sin_port = htons(zappy->net->port);
  zappy->net->cin_client.sin_family = AF_INET;
  zappy->net->cin_size = sizeof(zappy->net->cin_client);
  if (errors[0] == INIT_FAILURE || errors[1] == INIT_FAILURE)
    return (INIT_FAILURE);
  return (INIT_SUCCESS);
}

int			init_socket(t_zappy *zappy)
{
  int			errors[4];

  zappy->net->proto = getprotobyname("tcp");
  zappy->net->s_serv = my_xsocket(AF_INET, SOCK_STREAM,
				  zappy->net->proto->p_proto);
  errors[0] = zappy->net->s_serv;
  errors[1] = init_sockets(zappy);
  errors[2] = my_xbind(zappy->net->s_serv, (SOCKADDR *)&zappy->net->sin_serv,
		       zappy->net->sin_size);
  errors[3] = my_xlisten(zappy->net->s_serv, zappy->net->max_clients);
  if (errors[0] == INIT_FAILURE || errors[1] == INIT_FAILURE ||
      errors[2] == INIT_FAILURE || errors[3] == INIT_FAILURE)
    return (INIT_FAILURE);
  return (INIT_SUCCESS);
}
