/*
** rfc_graph_pex.c for pex.c in /home/mille_j//zappy/serveur/src/rfc_graph
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jun 30 08:28:10 2011 john mille
** Last update Thu Jun 30 08:39:42 2011 john mille
*/

#include <stdio.h>
#include "zappy.h"

void			rfc_graph_smg(int socket, char *msg)
{
  dprintf(socket, "smg %s\n", msg);
}
