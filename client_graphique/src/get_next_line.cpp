/*
** get_next_line.c for my_ftp in /u/all/el-out_y/cu/rendu/c/my_ftp
** 
** Made by youssef el-outmani
** Login   <el-out_y@epitech.net>
** 
** Started on  Sun Apr  3 23:19:19 2011 youssef el-outmani
// Last update Fri Jun 24 05:53:50 2011 youssef el-outmani
*/

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "gnl.hpp"

static char		*my_realloc(char *tab, int i, int nb)
{
  char			*str;
  int			pos;

  pos = 0;
  if ((str = (char *)malloc((nb + i) * sizeof(*str))) == NULL)
    exit(EXIT_FAILURE);
  while (pos < i)
    {
      str[pos] = tab[pos];
      pos++;
    }
  free(tab);
  return (str);
}

static int		end_buff(int i, t_struct *file, t_struct *line, int fd)
{
  while (i == file->nb)
    {
      i = 0;
      if ((file->nb = read(fd, file->tab, BUFF_SIZE)) <= 0)
	{
	  line->tab[line->pos] = '\0';
	  return (0);
	}
      file->tab[file->nb] = '\0';
      line->tab = my_realloc(line->tab, line->pos, file->nb);
      while (file->tab[i] != '\n' && file->tab[i] != '\0')
	line->tab[(line->pos)++] = file->tab[i++];
    }
  return (i);
}

static void		*init(t_struct *file, int fd)
{
  if (file->cpt == 0)
    {
      file->tab = (char *)malloc(sizeof(*file->tab) * BUFF_SIZE);
      file->nb = read(fd, file->tab, BUFF_SIZE);
      if (file->tab == NULL || file->nb == -1)
	return (NULL);
      file->tab[file->nb] = '\0';
      file->cpt = 1;
    }
  return ((void *)1);
}

char			*get_next_line(const int fd)
{
  static t_struct	file;
  static t_struct	line;
  static int		old_fd = -1;

  if (old_fd == -1 || old_fd != fd)
    {
      old_fd = fd;
      memset(&file, 0, sizeof(file));
      memset(&line, 0, sizeof(file));
    }
  line.pos = 0;
  if (init(&file, fd) == NULL)
    return (NULL);
  if (file.nb <= 0)
    return (0);
  if ((line.tab = (char *)malloc((file.nb) * sizeof(*line.tab))) == NULL)
    exit(EXIT_FAILURE);
  while (file.tab[line.cpt] != '\n' && file.tab[line.cpt] != '\0')
    line.tab[(line.pos)++] = file.tab[(line.cpt)++];
  line.cpt = end_buff(line.cpt, &file, &line, fd);
  if (line.cpt++ == -1)
    return (line.tab);
  line.tab[line.pos] = '\0';
  return (line.tab);
}
