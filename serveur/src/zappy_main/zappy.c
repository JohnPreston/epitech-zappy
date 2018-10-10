/*
** zappy.c for zappy in /home/mille_j/zappy/serveur/src
**
** Made by John Mille
** Login   <mille_j@epitech.net>
**
** Started on  Tue Jun 14 03:25:32 2011 John Mille
** Last update Thu Jul  7 20:21:53 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

int			main(int argc, char **argv)
{
  t_zappy		zappy;

  zappy.nb_clients = 0;
  zappy.id_client = 0;
  zappy.id_client_ok = 0;
  zappy.nb_incant = 0;
  if (build(argc, argv, &zappy))
    {
      init_socket(&zappy);
      loop(&zappy);
      destroy_zappy(&zappy);
    }
  return (EXIT_SUCCESS);
}
