/*
** build_teams.c for build teams in /home/mille_j/zappy/serveur
**
** Made by John Mille
** Login   <mille_j@epitech.net>
**
** Started on  Sun Jun 12 06:46:17 2011 John Mille
** Last update Thu Jul  7 19:18:35 2011 john mille
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

static int		count_teams(char **argv, int i)
{
  int			j[2];

  j[0] = i;
  j[1] = 0;
  while (my_strncmp(argv[j[0]], "-", 1))
    {
      j[0] += 1;
      j[1] += 1;
    }
  return (j[1]);
}

static t_teams		*init_teams(t_zappy *zappy)
{
  t_teams		*teams;
  t_teams		*waiting;
  t_teams		*graphic;
  t_teams		*incantations;

  teams = NULL;
  waiting = create_team("Waiting", 0, zappy->net->max_clients);
  teams = add_team(teams, waiting);
  graphic = create_team("GRAPHIC", 1, zappy->net->max_clients);
  teams = add_team(teams, graphic);
  incantations = create_team("incantations", 2, zappy->net->max_clients);
  teams = add_team(teams, incantations);
  return (teams);
}

void			build_teams(t_zappy *zappy, char **argv, int i)
{
  t_teams		*teams;
  t_teams		*new;
  int			nb_teams;
  int			j;

  j = 0;
  i += 1;
  teams = NULL;
  teams = init_teams(zappy);
  nb_teams = count_teams(argv, i);
  zappy->nb_teams = nb_teams + 3;
  while (j < nb_teams)
    {
      new = create_team(argv[i], (j + 3), zappy->net->max_clients);
      teams = add_team(teams, new);
      j += 1;
      i += 1;
    }
  zappy->teams = teams;
}
