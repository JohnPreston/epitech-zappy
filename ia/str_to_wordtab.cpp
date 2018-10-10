/*
** my_str_to_wordtab.c for  in /home/periph_a//zappi/client
** 
** Made by alexandre periphanos
** Login   <periph_a@epitech.net>
** 
** Started on  Tue Jun 21 17:02:33 2011 alexandre periphanos
// Last update Wed Jun 29 17:39:51 2011 alexandre periphanos
*/

#include <iostream>
#include <string>
#include <list>

static int		get_ends(int begin, char *s, char delim)
{
  int c = begin;

  while (s[c] != '\0' && s[c] != delim)
    {
      c++;
    }
  return (c + 1);
}

static int		count_word(char *str, char delim)
{
  int count = 1;
  int last;
  int i;
  for(i = 0; str[i] != '\0';++i)
    if (str[i] == delim)
      {
	last = i;
	count++;
      }
  if (i == last + 1)
    --count;
  return (count);
}

std::list<std::string>	 *str_to_wordtab(char *str, char delim)
{
  int begin = 0;
  int end;
  
  if (str == 0)
    return (0);
  std::list<std::string> * tab = new std::list<std::string>;
  int count = count_word(str, delim);
  int c = 0;

  while (c < count)
    {
      end = get_ends(begin, str, delim);
      std::string neo(str, begin, end - begin );
      tab->push_back(neo);
      begin = end + 1;
      c++;
    }
  return (tab);
}
