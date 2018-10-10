//
// Monitor.hpp for zappy in /home/el-out_y//zappy
// 
// Made by youssef el-outmani
// Login   <el-out_y@epitech.net>
// 
// Started on  Mon Jun 20 12:45:04 2011 youssef el-outmani
// Last update Sat Jul  9 08:27:22 2011 youssef el-outmani
//

#ifndef		__MONITOR__
# define	__MONITOR__

# include <string>
# include <map>
# include <list>
# include <vector>

# include "Game.hpp"
# include "Color.hpp"
# include "Image.hpp"
# include "Socket.hpp"
# include "Camera.hpp"

namespace	zappy
{

  enum		e_dir
    {
      NORTH = 1,
      EAST,
      SOUTH,
      WEST
    };

  enum		e_status
    {
      EGG,
      GHOST
    };

  struct	s_size
  {
    int		x;
    int		y;
  };

  struct	s_case
  {
    int		food;
    int		linemate;
    int		deraumere;
    int		sibur;
    int		mendiane;
    int		phiras;
    int		thystame;

    void	draw(s_size);
    void	draw_food(s_size);
    void	draw_floor(s_size);
    void	draw_mineral(s_size, gdl::Image, int, int);
  };

  struct	s_char
  {
    int		id;
    s_size	pos;
    int		dir;
    int		level;
    std::string	team;
    gdl::Color	color;

    void	draw(void);
  };

  struct	s_egg
  {
    int		id;
    int		plid;
    s_size	pos;
    e_status	status;

    void	draw(void);
  };

  class		Monitor : public gdl::Game
  {
  private :
    Camera	camera_;
    Socket	socket_;
    s_size	size_;
    int		time_;
    std::list<s_egg *>				egg_;
    std::list<s_char *>				pl_;
    std::list<std::list<s_case *>* >	map_;

    void	initMap(void);
    void	createMap(void);
    void	addNewPlayer(s_char&);
    void	updatePlayer(int, int, int, e_dir);
    void	removePlayer(int);
    void	addNewEgg(s_egg&);
    void	removeEgg(int);
    void	doAction(std::string);

  public :
    void	connect(std::string, int);
    void	connect(std::string, std::string);
    void	initialize(void);
    void	update(void);
    void	draw(void);
    void	unload(void);
  };

}

#endif
