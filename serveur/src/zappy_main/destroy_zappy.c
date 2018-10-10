/*
** destroy_zappy.c for destroy zappy in /home/mille_j/zappy/serveur/src
**
** Made by John Mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jun 14 03:34:04 2011 John Mille
** Last update Tue Jun 14 17:48:14 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

void			destroy_zappy(t_zappy *zappy)
{
  my_xclose(zappy->net->s_serv);
  zappy->net->fd = my_xfree(zappy->net->fd);
  zappy->net = my_xfree(zappy->net);
  zappy->map = my_xfree(zappy->map);
}
