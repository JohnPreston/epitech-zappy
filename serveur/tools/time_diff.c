/*
** time_diff.c for time diff in /home/mille_j//zappy/serveur/src/exec_actions
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Sat Jul  2 14:23:22 2011 john mille
** Last update Sat Jul  2 18:11:11 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <sys/types.h>

int			time_is_gone(struct timeval *t2, struct timeval *t1)
{
  if ((t2->tv_sec - t1->tv_sec) > 0 && (t2->tv_usec - t1->tv_usec) < 0)
    return (1);
  else if ((t2->tv_sec - t1->tv_sec) == 0 && (t2->tv_usec - t1->tv_usec) > 0)
    return (1);
  return (0);
}
