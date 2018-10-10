//
// Camera.cpp for bomberman in /home/chen_b//BOMBERMAN/GDL
//
// Made by laurent chen
// Login   <chen_b@epitech.net>
//
// Started on  Thu May 26 16:18:14 2011 laurent chen
// Last update Sat Jul  9 07:31:14 2011 youssef el-outmani
//

#include <iostream>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Input.hpp"
#include "Camera.hpp"

void		Camera::initialize(int a, int b)
{
  this->maxX_ = a * BLOCK_SIZE;
  this->maxZ_ = b * BLOCK_SIZE;
  this->x = this->maxX_ / 2;
  this->z = this->maxZ_ / 2;
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 1.0f, 50000.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(this->x, 2000.0f, this->z,
	    this->x, 0.0f, this->z + 100.0f,
	    0.0f, 1.0f, 0.0f);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

void		Camera::update(gdl::Input input)
{
  if (input.isKeyDown(gdl::Keys::Right) && this->x > 0)
    this->x -= 30;
  else if (input.isKeyDown(gdl::Keys::Left) && this->x < this->maxX_)
    this->x += 30;
  else if (input.isKeyDown(gdl::Keys::Down) && this->z > 0)
    this->z -= 30;
  else if (input.isKeyDown(gdl::Keys::Up) && this->z < this->maxZ_)
    this->z += 30;
  glPopMatrix();
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 1.0f, 50000.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(this->x, 2000.0f, this->z,
	    this->x, 0.0f, this->z + 100.0f,
	    0.0f, 1.0f, 0.0f);
}

float		Camera::getX(void)
{
  return (this->x / BLOCK_SIZE);
}

float		Camera::getZ(void)
{
  return (this->z / BLOCK_SIZE);
}
