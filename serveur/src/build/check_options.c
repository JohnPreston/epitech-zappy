/*
** check_options.c for check options in /home/mille_j/zappy/serveur/src/cmd_line_parsing
**
** Made by John Mille
** Login   <mille_j@epitech.net>
**
** Started on  Sat Jun 11 04:44:03 2011 John Mille
** Last update Tue Jul  5 04:21:36 2011 john mille
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "cmd_parsing.h"
#include "my.h"

int			my_strisnum(char *str);

static t_options	gl_options[] = {
  {1, 1024, 65535, "-p", USAGE_OPTION_1, check_options},
  {2, 8, 4096, "-x", USAGE_OPTION_2, check_options},
  {3, 8, 4096, "-y", USAGE_OPTION_3, check_options},
  {4, 0, 0, "-n", USAGE_OPTION_4, check_teams},
  {5, 1, 1024, "-c", USAGE_OPTION_5, check_options},
  {6, 1, 10000, "-t", USAGE_OPTION_6, check_options},
  {0, 0, 0, NULL, NULL, NULL}
};

int			check_teams(char **argv, int opt, int i)
{
  if (!(argv[i + 1]))
    {
      fprintf(stderr, "%s", gl_options[opt].usage);
      return (0);
    }
  return (1);
}

int			check_options(char **argv, int opt, int i)
{
  float			nb;

  nb = -1;
  if (!(argv[i + 1]))
    {
      fprintf(stderr, "%s", gl_options[opt].usage);
      return (0);
    }
  else if (argv[i + 1] && my_strisnum(argv[i + 1]))
    {
      nb = my_getnbr(argv[i + 1]);
      if (nb < gl_options[opt].value_min ||
	  nb > gl_options[opt].value_max ||
	  nb < 0)
	{
	  fprintf(stderr, "%s", gl_options[opt].usage);
	  return (0);
	}
    }
  else if (argv[i = 1] && !my_strisnum(argv[i + 1]))
    {
      fprintf(stderr, "%s", gl_options[opt].usage);
      return (0);
    }
  return (1);
}

int			man(void)
{
  fprintf(stderr, "Usage: ./server -p port -x width -y height ");
  fprintf(stderr, "-n team_names -c max_clients -t time_unit\n");
  return (0);
}

int			check_cmd_line(int argc, char **argv)
{
  int			i[3];

  if (argc == 1)
    return (man());
  i[0] = 0;
  i[2] = 0;
  while (gl_options[i[0]].id)
    {
      i[1] = 1;
      while (argv[i[1]])
	{
	  if (my_strcmp(argv[i[1]], gl_options[i[0]].flag) == 0 &&
	      gl_options[i[0]].func)
	    i[2] += gl_options[i[0]].func(argv, i[0], i[1]);
	  i[1] += 1;
	}
      i[0] += 1;
    }
  if (i[2] == 6)
    return (1);
  man();
  return (0);
}
