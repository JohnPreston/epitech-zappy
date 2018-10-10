//
// main.cpp for  in /home/periph_a//zappi/client
// 
// Made by alexandre periphanos
// Login   <periph_a@epitech.net>
// 
// Started on  Fri Jun 17 21:40:55 2011 alexandre periphanos
// Last update Wed Jul  6 16:48:13 2011 alexandre periphanos
//

#include <iostream>
#include "client.hh"
#include "stream_manip.hh"
#include "argsParser.hh"

static void usage()
{
  std::cout << "./client_zappy -n nomdequipe -p port [-h nomdelamachine]" << std::endl;
  exit(EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    
  if (ac > 4)
    {
      argsParser parser(ac, av);
      Client client(parser.getPort(), parser.getTeam(), parser.getIP());
      client.loop();
    }
  else
    usage();
}
