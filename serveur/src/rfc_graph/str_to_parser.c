/*
** str_to_parser.c for str to parser in /home/mille_j//zappy/serveur/src/parsing
**
** Made by john mille
** Login   <mille_j@epitech.net>
**
** Started on  Fri Jun 24 05:04:37 2011 john mille
** Last update Thu Jun 30 05:54:09 2011 john mille
*/

#include <stdlib.h>
#include "my.h"

int		char_ok(char c)
{
  int		i;

  i = 0;
  if ((c >= ' ' && c <= '~') &&
      (c != '\t' && c != ' ' && c != '\n'))
    return (1);
  return (0);
}

char		*fill_tab(char *tab, char *str, int i)
{
  int		j;

  j = 0;
  while (char_ok(str[i + j]) == 1 && (i + j) < my_strlen(str))
    j += 1;
  tab = my_xxmalloc((j + 1) * sizeof(*tab));
  j = 0;
  while (char_ok(str[i + j]) == 1 && (i + j) < my_strlen(str))
    {
      tab[j] = str[i + j];
      j += 1;
    }
  return (tab);
}

int		nb_words(char *str)
{
  int		nb;
  int		in;
  int		i;

  nb = 0;
  in = 0;
  i = 0;
  if (!str)
    return (0);
  while (str[i])
    {
      if (char_ok(str[i]) == 1 && in == 0)
	{
	  nb += 1;
	  in = 1;
	}
      else if (char_ok(str[i]) == 0 && in == 1)
	in = 0;
      i += 1;
    }
  return (nb);
}

char		**str_parser(char *str)
{
  char		**tab;
  int		nb;
  int		in;
  int		i;

  nb = 0;
  in = 0;
  i = 0;
  tab = my_xmalloc((nb_words(str) + 1) * sizeof(*tab));
  while (str[i])
    {
      if (char_ok(str[i]) == 1 && in == 0)
	{
	  tab[nb] = fill_tab(tab[nb], str, i);
	  nb += 1;
	  in = 1;
	}
      else if (char_ok(str[i]) == 0 && in == 1)
	in = 0;
      i += 1;
    }
  tab[nb] = NULL;
  return (tab);
}
