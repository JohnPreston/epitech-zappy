/*
** put_ressource.c for zpy in /home/chen_b//zappy/serveur/src/rfc_player
**
** Made by laurent chen
** Login   <chen_b@epitech.net>
**
** Started on  Tue Jul  5 16:59:35 2011 laurent chen
** Last update Fri Jul  8 06:48:45 2011 john mille
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "zappy.h"
#include "my.h"

void			put_deraumere(t_chars *c, t_zappy *z)
{
  if (c->invent->deraumere > 0)
    {
      c->invent->deraumere -= 1;
      z->map->cases[c->pos_x][c->pos_y].deraumere += 1;
      rfc_graph_mct_serv(z);
      my_xwrite(c->s_chars, "ok\n", 4);
      rfc_graph_pin_serv(z);
    }
  else
    my_xwrite(c->s_chars, "ko\n", 4);
}

void			put_sibur(t_chars *c, t_zappy *z)
{
  if (c->invent->sibur > 0)
    {
      c->invent->sibur -= 1;
      z->map->cases[c->pos_x][c->pos_y].sibur += 1;
      rfc_graph_mct_serv(z);
      rfc_graph_pin_serv(z);
      my_xwrite(c->s_chars, "ok\n", 4);
    }
  else
    my_xwrite(c->s_chars, "ko\n", 4);
}

void			put_mendiane(t_chars *c, t_zappy *z)
{
  if (c->invent->mendiane > 0)
    {
      c->invent->mendiane -= 1;
      z->map->cases[c->pos_x][c->pos_y].mendiane += 1;
      rfc_graph_mct_serv(z);
      rfc_graph_pin_serv(z);
      my_xwrite(c->s_chars, "ok\n", 4);
    }
  else
    my_xwrite(c->s_chars, "ko\n", 4);
}

void			put_phiras(t_chars *c, t_zappy *z)
{
  if (c->invent->phiras > 0)
    {
      c->invent->phiras -= 1;
      z->map->cases[c->pos_x][c->pos_y].phiras += 1;
      rfc_graph_pin_serv(z);
      rfc_graph_mct_serv(z);
      my_xwrite(c->s_chars, "ok\n", 4);
    }
  else
    my_xwrite(c->s_chars, "ko\n", 4);
}

void			put_thystame(t_chars *c, t_zappy *z)
{
  if (c->invent->thystame > 0)
    {
      c->invent->thystame -= 1;
      z->map->cases[c->pos_x][c->pos_y].thystame += 1;
      rfc_graph_mct_serv(z);
      rfc_graph_pin_serv(z);
      my_xwrite(c->s_chars, "ok\n", 4);
    }
  else
    my_xwrite(c->s_chars, "ko\n", 4);
}
