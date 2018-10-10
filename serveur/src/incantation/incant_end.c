/*
** incant_failed.c for incant failed in /home/mille_j//zappy/serveur/src
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Thu Jul  7 23:27:42 2011 john mille
** Last update Fri Jul  8 10:52:19 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "zappy.h"

void			level_up(t_zappy *z, t_chars *incant)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;

  t_tmp = z->teams->next->next->next;
  while (t_tmp)
    {
      c_tmp = t_tmp->chars;
      while (c_tmp)
	{
	  if (c_tmp->pos_x == incant->pos_x &&
	      c_tmp->pos_y == incant->pos_y)
	    {
	      c_tmp->level += 1;
	      dprintf(c_tmp->s_chars, "niveau actuel : %d\n", c_tmp->level);
	      rfc_graph_plv_serv(z, c_tmp);
	    }
	  c_tmp = c_tmp->next;
	}
      t_tmp = t_tmp->next;
    }
  rfc_graph_pie(z, incant, 1);
}

void			incant_failed(t_zappy *z, t_chars *incant)
{
  t_teams		*t_tmp;
  t_chars		*c_tmp;

  t_tmp = z->teams->next->next->next;
  while (t_tmp)
    {
      c_tmp = t_tmp->chars;
      while (c_tmp)
	{
	  if (incant != c_tmp && c_tmp->pos_x == incant->pos_x &&
	      c_tmp->pos_y == incant->pos_y)
	    dprintf(c_tmp->s_chars, "ko\n");
	  c_tmp = c_tmp->next;
	}
      t_tmp = t_tmp->next;
    }
  rfc_graph_pie(z, incant, 0);
}
