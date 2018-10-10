/*
** my_xfunctions.c for x functions in /home/mille_j//zappy/serveur/src/networking
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Wed Jun 22 16:11:08 2011 john mille
** Last update Sun Jul  3 16:49:25 2011 john mille
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int			my_xread(const int fd, char *buff, unsigned int size)
{
  int			xread;

  xread = read(fd, buff, size);
  if (xread == -1)
    perror("read");
  return (xread);
}

int			my_xwrite(const int fd, char *buff, unsigned int size)
{
  int			xwrite;

  xwrite = write(fd, buff, size);
  if (xwrite == -1)
    perror("write");
  return (xwrite);
}

int			my_xclose(int fd)
{
  int			closed;

  closed = close(fd);
  if (closed == -1)
      perror("close");
  return (closed);
}

int			my_strisnum(char *str)
{
  int			i;

  i = 0;
  while (str[i])
    {
      if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
	i += 1;
      else
	return (0);
    }
  return (1);
}
