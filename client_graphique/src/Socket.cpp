//
// Socket.cpp for zappy in /home/el-out_y//zappy
// 
// Made by youssef el-outmani
// Login   <el-out_y@epitech.net>
// 
// Started on  Mon Jun 20 12:58:32 2011 youssef el-outmani
// Last update Sat Jul  9 07:44:27 2011 youssef el-outmani
//

#include	<iostream>
#include	<cstdlib>
#include	<unistd.h>
#include	<netdb.h>
#include	<sys/types.h>
#include	<sys/socket.h>
#include	<netinet/in.h>
#include	<arpa/inet.h>

#include	"Socket.hpp"
#include	"gnl.hpp"

void		Socket::createSocket(std::string proto)
{
  int			s;
  int			flag;
  struct protoent	*pe;

  pe = getprotobyname(proto.c_str());
  s = socket(AF_INET, SOCK_STREAM, pe->p_proto);
  if (s == -1)
    {
      std::cerr << "Socket creation failure" << std::endl;
      exit(EXIT_SUCCESS);
    }
  setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &flag, sizeof(flag));
  this->socket_ = s;
}

void		Socket::Connect(void)
{
  struct sockaddr_in	sin;

  sin.sin_family = AF_INET;
  sin.sin_addr.s_addr = inet_addr(this->ip_.c_str());
  sin.sin_port = htons(this->port_);
  if (connect(this->socket_, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      std::cerr << "Connection error" << std::endl;
      close(this->socket_);
      this->socket_ = 0;
      exit(EXIT_FAILURE);
    }
}

void		Socket::initSocket(std::string ip, int port)
{
  std::string	proto("TCP");

  this->ip_ = ip;
  this->port_ = port;
  createSocket(proto);
}

int		Socket::checkMsg(void)
{
  fd_set	readFds;
  fd_set	writeFds;
  timeval	tv;

  tv.tv_sec = 0;
  tv.tv_usec = 0;
  FD_ZERO(&readFds);
  FD_SET(this->socket_, &readFds);
  select(this->socket_ + 1, &readFds, &writeFds, NULL, &tv);
  if (FD_ISSET(this->socket_, &readFds))
    return (1);
  return (0);
}

std::string	Socket::catchMsg(void)
{
  std::string	msg;
  char		*str;

  if ((str = get_next_line(this->socket_)) == NULL)
    {
      std::cerr << "Connection lost" << std::endl;
      exit(EXIT_FAILURE);
    }
  msg = str;
  return (msg);
}

void		Socket::sendMsg(std::string msg)
{
  dprintf(this->socket_, "%s\n", msg.c_str());
}
