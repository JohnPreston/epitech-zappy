//
// Monitor.cpp for zappy in /home/el-out_y//zappy
//
// Made by youssef el-outmani
// Login   <el-out_y@epitech.net>
//
// Started on  Mon Jun 20 12:43:39 2011 youssef el-outmani
// Last update Sat Jul  9 11:31:20 2011 youssef el-outmani
//

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <GL/gl.h>
#include <GL/glu.h>

#include "Model.hpp"
#include "Image.hpp"
#include "Monitor.hpp"

namespace zappy
{

  gdl::Model	modPl = gdl::Model::load("assets/models/marvin.fbx");
  gdl::Model	modEgg = gdl::Model::load("assets/models/bomb.fbx");
  gdl::Image    gazon = gdl::Image::load("assets/textures/gazon.jpg");
  gdl::Image    food = gdl::Image::load("assets/textures/food.jpg");
  gdl::Image    linemateT = gdl::Image::load("assets/textures/linemate.jpg");
  gdl::Image    deraumereT = gdl::Image::load("assets/textures/deraumere.jpg");
  gdl::Image    siburT = gdl::Image::load("assets/textures/sibur.jpg");
  gdl::Image    mendianeT = gdl::Image::load("assets/textures/mendiane.jpg");
  gdl::Image    phirasT = gdl::Image::load("assets/textures/phiras.jpg");
  gdl::Image    thystameT = gdl::Image::load("assets/textures/thystame.jpg");

  void		Monitor::connect(std::string ip, std::string port)
  {
    std::stringstream	ss(port);
    int		p;

    ss >> p;
    this->socket_.initSocket(ip, p);
    this->socket_.Connect();
  }

  void		Monitor::connect(std::string ip, int port)
  {
    this->socket_.initSocket(ip, port);
    this->socket_.Connect();
  }

  void		Monitor::createMap(void)
  {
    for(int i = 0; i < this->size_.x; i++)
      this->map_.push_back(new std::list<s_case *>);
    std::list<std::list<s_case *>* >::iterator itb = this->map_.begin();
    for (; itb != this->map_.end(); ++itb)
      for (int i = 0; i < this->size_.y; i++)
	(*itb)->push_back(new s_case);
  }

  void		Monitor::initMap(void)
  {
    std::list<std::list<s_case *>* >::iterator itb = this->map_.begin();
    for (; itb != this->map_.end(); ++itb)
      {
	std::list<s_case *>::iterator it = (*itb)->begin();
	for (; it != (*itb)->end(); ++it)
	  {
	    (*it)->food = 0;
	    (*it)->linemate = 0;
	    (*it)->deraumere = 0;
	    (*it)->sibur = 0;
	    (*it)->mendiane = 0;
	    (*it)->phiras = 0;
	    (*it)->thystame = 0;
	  }
      }
  }

  void		Monitor::addNewPlayer(s_char& pl)
  {
    s_char	*newpl = new s_char;

    newpl->id = pl.id;
    newpl->dir = pl.dir;
    newpl->pos.x = pl.pos.x;
    newpl->pos.y = pl.pos.y;
    newpl->level = pl.level;
    newpl->team = pl.team;
    this->pl_.push_front(newpl);
  }

  void		Monitor::removePlayer(int id)
  {
    std::list<s_char *>::iterator itb = this->pl_.begin();
    for (; itb != this->pl_.end(); ++itb)
      {
	if ((*itb)->id == id)
	  {
	    delete (*itb);
	    this->pl_.erase(itb);
	    break;
	  }
      }
  }

  void		Monitor::addNewEgg(s_egg& egg)
  {
    s_egg		*newegg = new s_egg;

    newegg->id = egg.id;
    newegg->plid = egg.plid;
    newegg->pos.x = egg.pos.x;
    newegg->pos.y = egg.pos.y;
    newegg->status = EGG;
    this->egg_.push_front(newegg);
  }

  void		Monitor::removeEgg(int id)
  {
    std::list<s_egg *>::iterator itb = this->egg_.begin();
    for (; itb != this->egg_.end(); ++itb)
      {
	if ((*itb)->id == id)
	  {
	    delete (*itb);
	    this->egg_.erase(itb);
	    break;
	  }
      }
  }

  void		Monitor::updatePlayer(int id, int x, int y, e_dir dir)
  {
    std::list<s_char *>::iterator itb = this->pl_.begin();
    for (; itb != this->pl_.end(); ++itb)
      {
	if ((*itb)->id == id)
	  {
	    (*itb)->pos.x = x;
	    (*itb)->pos.y = y;
	    (*itb)->dir = dir;
	    break;
	  }
      }
  }

  void		Monitor::doAction(std::string cmd)
  {
    std::istringstream	line(cmd);
    std::string		word;

    line >> word;
    if (word == "BIENVENUE")
      this->socket_.sendMsg("GRAPHIC");
    else if (word == "msz")
      {
	line >> this->size_.x;
	line >> this->size_.y;
	this->createMap();
	this->initMap();
	this->camera_.initialize(this->size_.x, this->size_.y);
      }
    else if (word == "bct")
      {
	int	x;
	int	y;

	line >> x;
	line >> y;
	std::list<std::list<s_case *>* >::iterator itb = this->map_.begin();
	for (int i = 0; itb != this->map_.end(); ++itb, i++)
	  {
	    std::list<s_case *>::iterator it = (*itb)->begin();
	    for (int j = 0; it != (*itb)->end(); ++it, j++)
	      {
		if (i == x && j == y)
		  {
		    line >> (*it)->food;
		    line >> (*it)->linemate;
		    line >> (*it)->deraumere;
		    line >> (*it)->sibur;
		    line >> (*it)->mendiane;
		    line >> (*it)->phiras;
		    line >> (*it)->thystame;
		    break;
		  }
	      }
	  }
      }
    else if (word == "pnw")
      {
	s_char		*pl = new s_char;
	int		c = 0;

	line >> pl->id;
	line >> pl->pos.x;
	line >> pl->pos.y;
	line >> pl->dir;
	line >> pl->level;
	line >> pl->team;
	for (unsigned int i = 0; i < pl->team.size(); i++)
	  c += pl->team[i];
	c *= getpid();
	gdl::Color	color((c * 10) % 255, (c * 5) % 255, (c * 8) % 255);
	pl->color = color;
	this->pl_.push_front(pl);
      }
    else if (word == "ppo")
      {
	int	id;

	line >> id;
	std::list<s_char *>::iterator it = this->pl_.begin();
	for (; it != this->pl_.end(); ++it)
	  {
	    if ((*it)->id == id)
	      {
		line >> (*it)->pos.x;
		line >> (*it)->pos.y;
		line >> (*it)->dir;
		break;
	      }
	  }
      }
    else if (word == "plv")
      {
	int	id;

	line >> id;
	std::list<s_char *>::iterator it = this->pl_.begin();
	for (; it != this->pl_.end(); ++it)
	  {
	    if ((*it)->id == id)
	      {
		line >> (*it)->level;
		break;
	      }
	  }
      }
    else if (word == "pbc")
      {
	int		id;
	std::string	str;

	line >> id;
	std::cout << "Le joueur " << id << " dit : ";
	while (line.tellg() > 0)
	  {
	    line >> str;
	    std::cout << str << " ";
	  }
	std::cout << std::endl;
      }
    else if (word == "pic")
      {
	s_size		pos;
	int		id;

	line >> pos.x;
	line >> pos.y;
	line >> id;
	std::cout << "le joueur " << id << " lance une incantation";
      }
    else if (word == "pfk")
      {
	int		id;

	line >> id;
	std::cout << "le joueur " << id << " pond un oeuf" << std::endl;
      }
    else if (word == "pdi")
      {
	int	id;

	line >> id;
	std::list<s_char *>::iterator it = this->pl_.begin();
	for (; it != this->pl_.end(); ++it)
	  {
	    if ((*it)->id == id)
	      {
		delete (*it);
		this->pl_.erase(it);
		break;
	      }
	  }
      }
    else if (word == "edi")
      {
	int	id;

	line >> id;
	std::list<s_egg *>::iterator it = this->egg_.begin();
	for (; it != this->egg_.end(); ++it)
	  {
	    if ((*it)->id == id)
	      {
		delete (*it);
		this->egg_.erase(it);
		break;
	      }
	  }
	std::list<s_char *>::iterator itb = this->pl_.begin();
	for (; itb != this->pl_.end(); ++itb)
	  {
	    if ((*itb)->id == id)
	      {
		delete (*itb);
		this->pl_.erase(itb);
		break;
	      }
	  }
      }
    else if (word == "enw")
      {
	s_egg	*e = new s_egg;

	line >> e->id;
	line >> e->plid;
	line >> e->pos.x;
	line >> e->pos.y;
	e->status = EGG;
	this->egg_.push_front(e);
      }
    else if (word == "eht")
      {
	int	id;

	line >> id;
	std::list<s_egg *>::iterator it = this->egg_.begin();
	for (; it != this->egg_.end(); ++it)
	  {
	    if ((*it)->id == id)
	      (*it)->status = GHOST;
	  }
      }
    else if (word == "ebo")
      {
	int	id;

	line >> id;
	std::list<s_egg *>::iterator it = this->egg_.begin();
	for (; it != this->egg_.end(); ++it)
	  {
	    if ((*it)->id == id)
	      {
		delete (*it);
		this->egg_.erase(it);
		break;
	      }
	  }
      }
    else if (word == "seg")
      {
	std::string	team;

	line >> team;
	std::cout << "L'equipe " << team << " gagne !" << std::endl;
      }
    else if (word == "smg")
      {
	std::string	str;

	while (line.tellg() > 0)
	  {
	    line >> str;
	    std::cout << str << " ";
	  }
	std::cout << std::endl;
      }
  }

  void		Monitor::initialize(void)
  {
    this->window_.create();
  }

  void		Monitor::draw(void)
  {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.74f, 0.84f, 95.0f, 1.0f);
    glClearDepth(1.0f);
    std::list<std::list<s_case *>* >::iterator itb = this->map_.begin();
    for (int i = 0; itb != this->map_.end(); ++itb, i++)
      {
	std::list<s_case *>::iterator it = (*itb)->begin();
	for (int j = 0; it != (*itb)->end(); ++it, j++)
	  {
	    if ((i > this->camera_.getX() - 8 && i < this->camera_.getX() + 8) &&
		(j > this->camera_.getZ() - 8 && j < this->camera_.getZ() + 8))
	      {
		s_size	pos;

		pos.x = i;
		pos.y = j;
		(*it)->draw(pos);
	      }
	  }
      }
    std::list<s_egg *>::iterator ite = this->egg_.begin();
    for (; ite != this->egg_.end(); ++ite)
      if (((*ite)->pos.x > this->camera_.getX() - 8 && (*ite)->pos.x < this->camera_.getX() + 8) &&
	  ((*ite)->pos.y > this->camera_.getZ() - 8 && (*ite)->pos.y < this->camera_.getZ() + 8))
	(*ite)->draw();
    std::list<s_char *>::iterator itp = this->pl_.begin();
    for (; itp != this->pl_.end(); ++itp)
      if (((*itp)->pos.x > this->camera_.getX() - 8 && (*itp)->pos.x < this->camera_.getX() + 8) &&
	  ((*itp)->pos.y > this->camera_.getZ() - 8 && (*itp)->pos.y < this->camera_.getZ() + 8))
	(*itp)->draw();
  }

  void		Monitor::update(void)
  {
    if (this->input_.isKeyDown(gdl::Keys::Escape))
      this->unload();
    if (this->map_.size() != 0)
      this->camera_.update(this->input_);
    if (this->socket_.checkMsg())
      this->doAction(this->socket_.catchMsg());
  }

  void		Monitor::unload(void)
  {
    exit(EXIT_SUCCESS);
  }

  void		s_case::draw(s_size pos)
  {
    this->draw_floor(pos);
    if (this->food > 0)
      this->draw_food(pos);
    else if (this->linemate > 0)
      this->draw_mineral(pos, linemateT, 0, 0);
    else if (this->deraumere > 0)
      this->draw_mineral(pos, deraumereT, 1, 0);
    else if (this->sibur > 0)
      this->draw_mineral(pos, siburT, 2, 0);
    else if (this->mendiane > 0)
      this->draw_mineral(pos, mendianeT, 0, 1);
    else if (this->phiras > 0)
      this->draw_mineral(pos, phirasT, 1, 1);
    else if (this->thystame > 0)
      this->draw_mineral(pos, thystameT, 2, 1);
  }

  void		s_case::draw_food(s_size pos)
  {
    zappy::food.bind();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(pos.x * BLOCK_SIZE, 0.0f, pos.y * BLOCK_SIZE);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 6,-BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 6,-BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 6,-BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 6,-BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 6,-BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 6,-BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 6,-BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 6,-BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glEnd();
    glPopMatrix();
  }

  void		s_case::draw_mineral(s_size pos, gdl::Image mineral, int x, int y)
  {
    mineral.bind();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(((pos.x * BLOCK_SIZE) - (BLOCK_SIZE / 2)) + BLOCK_SIZE / 5 + BLOCK_SIZE / 3 * x,
		 0.0f,
		 ((pos.y * BLOCK_SIZE) - (BLOCK_SIZE / 2)) + BLOCK_SIZE / 5 + BLOCK_SIZE / 2 * y);

    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 6,-BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 6,-BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 6,-BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 6,-BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 6,-BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 6,-BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 6,-BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 6,-BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,BLOCK_SIZE / 6);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 6,BLOCK_SIZE / 6,-BLOCK_SIZE / 6);
    glEnd();
    glPopMatrix();
  }

  void		s_case::draw_floor(s_size pos)
  {
    gazon.bind();
    glEnable(GL_TEXTURE_2D);
    glPushMatrix();
    glTranslatef(pos.x * BLOCK_SIZE, 0.0f, pos.y * BLOCK_SIZE);

    glBegin(GL_QUADS);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-BLOCK_SIZE / 2, 0, -BLOCK_SIZE / 2);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-BLOCK_SIZE / 2, 0, BLOCK_SIZE / 2);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(BLOCK_SIZE / 2, 0, BLOCK_SIZE / 2);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(BLOCK_SIZE / 2, 0, -BLOCK_SIZE / 2);
    glEnd();
    glPopMatrix();
  }

  void		s_char::draw(void)
  {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(pos.x * BLOCK_SIZE, 0.0f,
		 pos.y * BLOCK_SIZE);
    if (dir == SOUTH)
      glRotatef(180.0f, 0.0f, 1.0f, 0.0f);
    else if (dir == EAST)
      glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    else if (dir == WEST)
      glRotatef(270.0f, 0.0f, 1.0f, 0.0f);
    modPl.set_default_model_color(this->color);
    gdl::Model::Begin();
    modPl.draw();
    gdl::Model::End();
    glPopMatrix();
  }

  void		s_egg::draw(void)
  {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(pos.x * BLOCK_SIZE, 0.0f,
		 pos.y * BLOCK_SIZE);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    gdl::Model::Begin();
    if (status == GHOST)
      modPl.draw();
    else
      modEgg.draw();
    gdl::Model::End();
    glPopMatrix();
  }
}
