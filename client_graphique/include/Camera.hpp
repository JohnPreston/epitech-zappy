//
// Camera.hpp for bomberman in /home/chen_b//BOMBERMAN/GDL
// 
// Made by laurent chen
// Login   <chen_b@epitech.net>
// 
// Started on  Thu May 26 16:00:09 2011 laurent chen
// Last update Sat Jul  9 07:31:12 2011 youssef el-outmani
//

#ifndef		__CAMERA_HPP__
# define	__CAMERA_HPP__

# define	BLOCK_SIZE 300

class	Camera
{
private :
  float		x;
  float		z;
  float		maxX_;
  float		maxZ_;

public :
  void		initialize(int, int);
  void		update(gdl::Input input);
  float		getX(void);
  float		getZ(void);
};

#endif	// !__CAMERA_HPP__
