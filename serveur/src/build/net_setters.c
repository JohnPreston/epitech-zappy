/*
** build_net.c for build net for zappy in /home/mille_j/zappy/serveur/src/cmd_line
**
** Made by John Mille
** Login   <mille_j@epitech.net>
**
** Started on  Sat Jun 11 16:07:52 2011 John Mille
** Last update Sun Jul  3 13:30:48 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			set_net_port(t_zappy *zappy, char **argv, int i)
{
  zappy->net->port = my_getnbr(argv[i + 1]);
}

void			set_max_clients(t_zappy *zappy, char **argv, int i)
{
  zappy->net->max_clients = my_getnbr(argv[i + 1]);
}
