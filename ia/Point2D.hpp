//
// Point2D.hpp for  in /home/periph_a//real_nibbler
// 
// Made by alexandre periphanos
// Login   <periph_a@epitech.net>
// 
// Started on  Wed Mar  9 12:18:26 2011 alexandre periphanos
// Last update Thu Jun 23 15:52:36 2011 alexandre periphanos
//

#ifndef _POINT2D_
#define _POINT2D_

/*
** Structure qui represente un simple point en 2D
*/

struct Point2D
{
  int x;
  int y;
  Point2D(int a = 0, int b = 0) : x(a), y(b){}
  void set(int a = 0, int b = 0){x=a;y=b;}
};

/*
** typedef sur des iterator un peu long a ecrire.
*/

#endif
