/*
** broadcast_to_graphic_team.c for broadcast to graphic team in /home/mille_j//zappy/serveur
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Sun Jul  3 19:03:06 2011 john mille
** Last update Sun Jul  3 19:09:34 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include "zappy.h"
#include "my.h"

void			broadcast_to_graphic_team(t_zappy *zappy, t_teams *t, t_chars *c, void *func)
{
  t_teams		*t_tmp;
  t_chars		*tmp;

  t_tmp = z->teams;
  t_tmp = t_tmp->next;
  tmp = t_tmp->chars;
  while (tmp)
    {

      tmp = tmp->next;
    }
}
