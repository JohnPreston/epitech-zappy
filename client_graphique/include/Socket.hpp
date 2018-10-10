//
// Socket.hpp<2> for zappy in /home/el-out_y//zappy
// 
// Made by youssef el-outmani
// Login   <el-out_y@epitech.net>
// 
// Started on  Mon Jun 20 12:58:49 2011 youssef el-outmani
// Last update Thu Jun 30 08:21:32 2011 youssef el-outmani
//

#ifndef		__SOCKET__
# define	__SOCKET__

# include	<cstdio>
# include	<string>
# include	<iostream>

class		Socket
{
private :
  int		socket_;
  int		port_;
  std::string	ip_;

  void		createSocket(std::string);

public :
  void		initSocket(std::string, int);
  void		Connect(void);
  int		checkMsg(void);
  std::string	catchMsg(void);
  void		sendMsg(std::string msg);
};

#endif
