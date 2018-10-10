/*
** test.c for zpy in /home/chen_b//zappy/serveur/src/broadcast
**
** Made by laurent chen
** Login   <chen_b@epitech.net>
**
** Started on  Sat Jul  2 16:01:09 2011 laurent chen
** Last update Thu Jul  7 16:20:59 2011 john mille
*/

#include		<stdio.h>
#include		"zappy.h"

int			get_direct(int x1, int y1, int x2, int y2)
{
  float			m;

  if (x1 != x2)
    m = (y1 - y2) / (x1 -  x2);
  if (y1 == y2 && x1 == x2)
    return (0);
  else if ((x1 == x2 && y1 > y2) || (m > 3 || m < -3))
    return (FRONT);
  else if ((x1 == x2 && y1 < y2) || (m > 3 || m < -3))
    return (BACK);
  if (m > -0.5 && m <= 0.5 && x1 > x2)
    return (RIGHT);
  else if (m > -0.5 && m <= 0.5 && x1 < x2)
    return (LEFT);
  if (m > 0.5 && m <= 3 && x1 > x2)
    return (FRONT_RIGHT);
  else if (m > 0.5 && m <= 3 && x1 < x2)
    return (BACK_LEFT);
  if (m > -3 && m <= -0.5 && x1 > x2)
    return (BACK_RIGHT);
  else if (m > -3 && m <= -0.5 && x1 > x2)
    return (FRONT_LEFT);
  return (8);
}

int			direct_4_char(int dir, int char_dir)
{
  if (dir != 0)
    {
      dir = dir - (char_dir - 1);
      if (dir < 0)
	dir = -dir;
      return (dir);
    }
  else
    return (dir);
}
