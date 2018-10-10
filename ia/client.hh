//
// client.hh for  in /home/periph_a//zappi
// 
// Made by alexandre periphanos
// Login   <periph_a@epitech.net>
// 
// Started on  Fri Jun 17 16:42:01 2011 alexandre periphanos
// Last update Wed Jul  6 16:46:42 2011 alexandre periphanos
//

#ifndef _CLIENT_
#define _CLIENT_

#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/time.h>
#include <string>
#include <vector>
#include <list>
#include "Point2D.hpp"
#include <netdb.h>

struct fac
{
  int i;
  int x;
  int y;
};

struct Case
{
  bool food;
  bool linemate;
  bool deraumere;
  bool sibur;
  bool mendiane;
  bool phiras;
  bool thystame;
  Case() :food(false), linemate(false), deraumere(false), sibur(false)
	 ,mendiane(false), phiras(false), thystame(false) {}
  void clean(){food = false; linemate = false; deraumere=false; sibur=false;
    mendiane=false; phiras=false; thystame=false;}
};

class Client
{
protected:
  int s;
  sockaddr_in sin;
  timeval tv;
  fd_set cdb;
  int dimx;
  int dimy;
  Point2D pos;
  int lvl;
  int ori;
  std::vector<Case> map;
  int port_;
  std::string team_;
  std::string ip_;
  Point2D direction;
  Point2D appel;
  int count;
  bool called;
  std::vector<int> sujets;
  bool end;
  int master;
  bool diriging;
  std::list<std::string> reqs;
  int member;

  void guider_la_team(int nb);
  void make_a_team(int nb);
  bool get_new_dir();
  bool wait_for_leave();
  int getcase(int);
  int coudey(int);
  int coudex(int);
  void actumap();
  void read_on_socket();
  void write_on_socket(std::string);
  void avance();
  void droite();
  void gauche();
  void broadcast(std::string);
  void rfork();
  bool incantation();
  bool prend(std::string);
  bool pose(std::string);
  bool expulse();
  void voir(std::string *);
  void inventaire(std::string *);
  int connect_nbr();
  void lvl2();
  void lvl3();
  void lvl4();
  void lvl5();
  void lvl6();
  void lvl7();
  void lvl8();
  bool check_return(bool = false,std::string * = NULL);
  void go_new(int port, std::string team, std::string ip);
  int go_to(int avant = 0, int droite = 0);
  void feed();
  void unblockfeed();
  void find(std::string, int = 1);
  void vider_case();
  void want_guys(int = 1);
  int is_guys(int = 1);
  void go_position();
  void traitement_broadcast(std::string);
  void traitement_deplacement(char *);
public:
  Client(int, std::string team, std::string ip = "localhost", int count_ = 0);
  ~Client();
  bool there_is_in_inventory(std::string, int = 1);
  virtual void loop();
};

std::list<std::string> *str_to_wordtab(char *, char);
std::vector<std::string> *str_to_wordtab2(const char *, char);

#endif
