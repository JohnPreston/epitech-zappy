/*
** tab_tools.c for tab_tools in /home/mille_j//rendu/c/42sh/lib
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 19:32:16 2010 john mille
** Last update Thu Dec  2 12:56:21 2010 john mille
*/

#include <stdlib.h>
#include "my.h"

void		my_show_tab(char **tab, char c)
{
  int		i;

  i = 0;
  if (tab)
    {
      while (tab[i] && tab)
	{
	  my_putstr(tab[i]);
	  my_putchar(c);
	  i += 1;
	}
    }
}

int		my_tablen(char **tab)
{
  int		i;

  i = 0;
  if (tab)
    {
      while (tab[i])
	i += 1;
    }
  return (i);
}
