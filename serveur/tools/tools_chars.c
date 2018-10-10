/*
** chars_tools.c for chars tools in /home/mille_j//zappy/serveur/src/networking
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Wed Jun 22 16:58:13 2011 john mille
** Last update Sun Jul 10 11:17:09 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "zappy.h"
#include "my.h"

t_chars				*create_char(unsigned int id,
					     SOCKET socket)
{
  t_chars			*new;

  new = my_xmalloc(sizeof(*new));
  memset(new, 0, sizeof(*new));
  new->id = id;
  new->is_egg = 0;
  new->is_ghost = 0;
  new->s_chars = socket;
  new->eat = NULL;
  new->invent = NULL;
  new->next = NULL;
  return (new);
}

t_chars				*add_char(t_chars *head, t_chars *new)
{
  t_chars			*fst;

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

t_chars				*delete_first_char(t_teams *t, int opt)
{
  t_chars			*tmp;

  tmp = t->chars;
  tmp = tmp->next;
  if (opt)
    {
      t->chars->s_chars = my_xclose(t->chars->s_chars);
      t->chars = my_xfree(t->chars);
    }
  return (tmp);
}

void				control_nb_players(t_teams *t)
{
  if ((t->max_members - 1) > t->max_members_init)
    t->max_members -= 1;
  t->nb_members -= 1;
}

t_chars				*delete_char(t_teams *teams, t_chars *to_del, int opt)
{
  t_chars			*head;
  t_chars			*tmp;

  head = teams->chars;
  if (to_del == head)
    teams->chars = delete_first_char(teams, opt);
  else if (head && head->next)
    {
      tmp = head;
      while (tmp->next)
	{
	  if (tmp->next == to_del)
	    {
	      if (opt)
		tmp->next->s_chars = my_xclose(tmp->next->s_chars);
	      tmp->next = tmp->next->next;
	      to_del = my_xfree(to_del);
	      return (teams->chars);
	    }
	  tmp = tmp->next;
	}
    }
  control_nb_players(teams);
  return (teams->chars);
}
