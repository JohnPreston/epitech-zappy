/*
** teams_tools.c for team tools in /home/mille_j/Documents/zappy/serveur/src/cmd_line
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Wed Jun 15 09:01:04 2011 john mille
** Last update Fri Jul  8 23:37:51 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include "zappy.h"
#include "my.h"

t_teams				*create_team(char *name,
					     int id,
					     unsigned int max_members)
{
  t_teams			*new;

  new = my_xmalloc(sizeof(*new));
  new->name = my_strdup(name);
  new->id = id;
  new->nb_members = 0;
  new->max_members = max_members;
  new->max_members_init = max_members;
  new->next = NULL;
  return (new);
}

t_teams				*add_team(t_teams *head, t_teams *new)
{
  t_teams			*fst;

  if (head)
    {
      fst = head;
      while (head->next)
	head = head->next;
      head->next = new;
      return (fst);
    }
  return (new);
}
