/*
** tab_functions.c for tab_functions in /home/mille_j//rendu/c/42sh/src
**
** Made by john mille
** Login   <John@epitech.net>
**
** Started on  Sun Oct  3 21:49:32 2010 john mille
** Last update Thu Jul  7 16:11:50 2011 john mille
*/

#include <stdlib.h>
#include "my.h"

char		**delete_first_elem_in_tab(char **old_array)
{
  char		**new_array;
  int		j;
  int		i;

  i = 0;
  j = 1;
  new_array = my_xmalloc((my_tablen(old_array) + 1) * sizeof(*new_array));
  while (old_array[j])
    {
      new_array[i] = my_strdup(old_array[j]);
      i += 1;
      j += 1;
    }
  new_array[i] = NULL;
  old_array = my_xfree_tab(old_array);
  return (new_array);
}
