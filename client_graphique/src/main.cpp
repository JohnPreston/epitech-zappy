//
// main.cpp for zappy in /home/el-out_y//zappy
// 
// Made by youssef el-outmani
// Login   <el-out_y@epitech.net>
// 
// Started on  Mon Jun 20 12:30:51 2011 youssef el-outmani
// Last update Thu Jul  7 02:44:37 2011 youssef el-outmani
//

#include <cstdlib>
#include <iostream>

#include "Monitor.hpp"

int			main(int ac, char **av)
{
  zappy::Monitor	m;
  std::string		ip;
  std::string		port;

  if (ac != 3)
    {
      std::cerr << "Usage : ./bin ip port" << std::endl;
      return (EXIT_FAILURE);
    }
  ip = av[1];
  port = av[2];
  m.connect(ip, port);
  m.run();
  return (EXIT_SUCCESS);
}
