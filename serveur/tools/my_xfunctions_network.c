/*
** xfunctions_network.c for xfunctions network in /media/data/my_ftp/src_common
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Mar 27 16:02:32 2011 john mille
** Last update Tue Jun 14 03:16:56 2011 John Mille
*/

#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

SOCKET			my_xsocket(int domain, int type, int protocol)
{
  SOCKET		sock;

  sock = socket(domain, type, protocol);
  if (sock == -1)
    perror("socket");
  return (sock);
}

int			my_xbind(SOCKET socketfd, SOCKADDR *addr, SOCKLEN addrlen)
{
  int			binden;

  binden = bind(socketfd, addr, addrlen);
  if (binden == -1)
    {
      my_xclose(socketfd);
      perror("bind");
    }
  return (binden);
}

int			my_xlisten(SOCKET socket, int backlog)
{
  int			hear;

  hear = listen(socket, backlog);
  if (hear == -1)
    perror("listen");
  return (hear);
}
