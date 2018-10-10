#include <sstream>
#include <string>
#include <stdlib.h>
#include <iostream>
int str_to_int(std::string s)
{
  int ret;
  std::stringstream ss(std::stringstream::in | std::stringstream::out);

  ss << s;
  ss >> ret;

  return (ret);
}

int str_to_int2(std::string s)
{
  int ret;
  std::stringstream ss(std::stringstream::in | std::stringstream::out);

  for (size_t i = 0; i < s.size(); i++)
  {
      if (s[i] < '0' || s[i] > '9')
      {
          std::cerr << s << " is NaN" << std::endl;
          exit(EXIT_SUCCESS);
      }
  }
  ss << s;
  ss >> ret;

  return (ret);
}

std::string int_to_str(int s)
{
  std::string ret;
  std::stringstream ss(std::stringstream::in | std::stringstream::out);

  ss << s;
  ss >> ret;

  return (ret);
}
