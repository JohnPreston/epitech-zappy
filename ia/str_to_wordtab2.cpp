/*
** my_str_to_wordtab.c for  in /home/periph_a//zappi/client
** 
** Made by alexandre periphanos
** Login   <periph_a@epitech.net>
** 
** Started on  Tue Jun 21 17:02:33 2011 alexandre periphanos
// Last update Wed Jun 29 18:30:17 2011 alexandre periphanos
*/

#include <string>
#include <vector>

static int		get_ends(int begin, const char *s, char delim)
{
  int c = begin;

  while (s[c] != '\0' && s[c] != delim)
    {
      c++;
    }
  return (c);
}

static int		count_word(const char *str, char delim)
{
  int count = 1;

  for(int i = 0; str[i] != '\0';++i)
    if (str[i] == delim)
      count++;
  return (count);
}

std::vector<std::string>	 *str_to_wordtab2(const char * str, char delim)
{
  int begin = 0;
  int end;
  
  if (str == 0)
    return (0);
  std::vector<std::string> * tab = new std::vector<std::string>;
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
  tab->push_back("end");
  return (tab);
}
