//
// client.cpp for  in /home/periph_a//zappi
// 
// Made by alexandre periphanos
// Login   <periph_a@epitech.net>
// 
// Started on  Fri Jun 17 16:38:23 2011 alexandre periphanos
// Last update Fri Jul  8 23:49:50 2011 alexandre periphanos
//

#include <unistd.h>
#include <cstring>
#include <iostream>
#include "info.hh"
#include "stream_manip.hh"
#include <algorithm>

static void std_err(std::string s)
{
  std::cerr << s << std::endl;
  exit(0);
}

Client::Client(int port, std::string team, std::string ip, int count_)
  : lvl(1), ori(1), port_(port), team_(team), ip_(ip), count(count_), called(false), end(false), master(-1), diriging(false)
{
  struct hostent *serveurHostEnt = NULL;

  appel.set(0,0);
  s = socket(PF_INET, SOCK_STREAM, 0);
  if (s == -1)
    std_err("Socket failed");
  
  serveurHostEnt = gethostbyname(ip.c_str());
  if (serveurHostEnt == NULL)
    std_err("probleme gethost");
  bcopy(serveurHostEnt->h_addr,&sin.sin_addr, serveurHostEnt->h_length);

  sin.sin_family = AF_INET;
  sin.sin_port = htons(port);
  tv.tv_sec = 5;
  tv.tv_usec = 0;
  
  if (connect(s, reinterpret_cast<sockaddr *>(&sin), sizeof(sin)) == -1)
    std_err("Connect failed");
  FD_ZERO(&cdb);
  FD_SET(s, &cdb);
  FD_SET(0, &cdb);
  if (select(s + 1, &cdb, NULL, NULL, &tv) == -1)
  std_err("Select failed");
  
  for (int i = 0; i < 1;)
    {
      read_on_socket();
      i += reqs.size();
      while (!reqs.empty())
	reqs.pop_front();
    }

  write_on_socket(team + "\n");
  
  for (int i = 0; i < 2;)
    {
      read_on_socket();
      i += reqs.size();
      while (!reqs.empty())
	{
	  reqs.pop_front();
	}
    }
}

Client::~Client()
{
  close(s);
}


void Client::read_on_socket()
{
  char buf[4096];
    int ret;
  int n;
  std::list<std::string> *tmp;

  memset(buf, 0, 4096);
  if ((ret = FD_ISSET(s, &cdb)) > 0)
    {
      n = read(s, buf, 4096);
      if (n <= 0 || write(1, buf, n) == -1)
        std_err("Something happened...");
    }
  if (ret < 0)
    std_err("Something happened...");
  tmp = str_to_wordtab(buf, '\n');

  if (reqs.empty())
    reqs = *tmp;
  else
    {
      reqs.front() = reqs.front() + tmp->front();
      tmp->pop_front();
      while (!tmp->empty())
	{
	  reqs.push_back(tmp->front());
	  tmp->pop_front();
	}
    }
  delete tmp;
}

void Client::write_on_socket(std::string mess)
{
  if (write(s, mess.c_str(), mess.length()) == -1)
    std_err("Something happened...");
}


void Client::avance()
{
  write_on_socket("avance\n");
  read_on_socket();
  check_return();
}

void Client::droite()
{
  write_on_socket("droite\n");
  read_on_socket();
  check_return();
}

void Client::gauche()
{
  write_on_socket("gauche\n");
  read_on_socket();
  check_return();
}

void Client::broadcast(std::string msg)
{
  msg = "broadcast " + msg + "\n"; 
  write_on_socket(msg.c_str());
  read_on_socket();
  check_return();
}

void Client::rfork()
{
  write_on_socket("fork\n");
  read_on_socket();
  check_return();
}

bool Client::incantation()
{
  std::string buf;
  int l = lvl;
 
  write_on_socket("incantation\n");
  read_on_socket();
  check_return(false, &buf);
  if (buf.find("ko") != buf.npos)
    return false;
  else
    {
      read_on_socket();
      check_return(true);
      if (lvl == l)
	return false;
    }
  return true;
}

bool Client::prend(std::string objet)
{
  std::string req("prend " + objet + "\n");
  
  write_on_socket(req.c_str());
  read_on_socket();
  return check_return();
}

bool Client::pose(std::string objet)
{
  std::string req("pose " + objet + "\n");
  write_on_socket(req.c_str());
  read_on_socket();
  return check_return();
}

bool Client::expulse()
{
  write_on_socket("expulse\n");
  read_on_socket();
  return check_return();
}

void Client::voir(std::string *buf)
{
  write_on_socket("voir\n");
  read_on_socket();
  check_return(false, buf);
}


void Client::inventaire(std::string *buf)
{
  write_on_socket("inventaire\n");
  read_on_socket();
  check_return(false, buf);
}

int Client::connect_nbr()
{
  write_on_socket("conect_nbr\n");
  read_on_socket();
  check_return();
  return (0);
}

void Client::traitement_broadcast(std::string s)
{
  if (master == -1 && !diriging && !called)
    {
      if (s.find(team_ + "need" + int_to_str(lvl)) != s.npos && str_to_int(s.c_str() + 10) < count)
	{
	  master = str_to_int(s.c_str() + 10);
	  called = true;
	}
      else if (s.find(team_ + "IMPOSITIONED1/" + int_to_str(count)) != s.npos && (std::find(sujets.begin(), sujets.end(),str_to_int(s.c_str() + 10)) == sujets.end()))
	{
	  sujets.push_back(str_to_int(s.c_str() + 10));
	  std::cout << count << " a decouvert "<< sujets.back() << "pour lvl " << lvl << " il en faut " << "/.\\" <<std::endl;
	  ++member;
	}
    }
  else if (diriging)
    {
      if (s.find(team_ + "IMPOSITIONED1/" + int_to_str(count)) != s.npos && (std::find(sujets.begin(), sujets.end(),str_to_int(s.c_str() + 10)) != sujets.end()))
	++member;
    }
  else if (called)
    {
      if (s.find(int_to_str(master) + "/" + team_ + "need" + int_to_str(lvl)) != s.npos)
	appel.set(dir[s[8] - 48].x, dir[s[8] - 48].y);
      else if (s.find(int_to_str(master)+"/"+team_ + "STOP" + int_to_str(lvl)) != s.npos)
	appel.set(0, 0);
      else if (s.find(int_to_str(master) + "/" + team_ + "Go") != s.npos)
	{
	  called = false;
	  master = -1;
	}
      else if (s.find("niveau") != reqs.front().npos)
	lvl++;
    }
}

bool Client::check_return(bool ret_for_lvl, std::string *buf)
{
  bool ret = false;
  bool have_rep = false;

  while (!have_rep)
    {
      while (!reqs.empty() && reqs.front()[reqs.front().size() - 1] == '\n')
	{
	  if (reqs.front().find("message") != reqs.front().npos)
	    traitement_broadcast(reqs.front());
	  else if (reqs.front().find("deplacement") != reqs.front().npos)
	    {
	      
	    }
	  else if (reqs.front().find("niveau") != reqs.front().npos)
	    {
	      lvl++;
	      if (ret_for_lvl)
		{
		  have_rep = true;
		  ret = true;
		}
	    }
	  else
	    {
	      have_rep = true;
	      if (reqs.front().find("ok") != reqs.front().npos)
		ret = true;
	      if (buf != NULL)
		*buf = reqs.front();
	    }
	  reqs.pop_front();
	}
      if (!have_rep)
	read_on_socket();
    }
  return ret;
}

int Client::go_to(int x, int y)
{
  int count = 0;

  if (!(x || y))
    {
      x = direction.x;
      y = direction.y;
    }
  if (x < 0)
    {
      droite();
      droite();
      count += 2;
      x*=-1;
    }
  count += x;
  for (x = x; x != 0; --x)
    avance();
  if (y)
    {
      if (y > 0)
        droite();
      else if (y < 0)
        {
          gauche();
          y = -y;
        }
      count += y + 1;
      for (y = y; y != 0; --y)
        avance();
    }
  return count;
}


void Client::unblockfeed()
{
  std::string s;
  std::vector<std::string> *vu;
  bool ok;

  for (int i = 0; i < 120; ++i)
    {
      voir(&s);
      vu = str_to_wordtab2(s.c_str(), ',');
      ok = false;
      for (unsigned int u = 0; (*vu)[u] != "end" && !ok; ++u)
        {
          if ((*vu)[u].find("nourriture") != (*vu)[u].npos)
            {
              direction.set(tab[u].x, tab[u].y);
              i += go_to();
              prend("nourriture");
              ++i;
              ok = true;
            }
        }
      if (!ok)
        {
          direction.set(lvl,0);
          i += go_to();
        }
      delete vu;
    }
}


void Client::go_new(int port, std::string team, std::string ip)
{
  int pid = -1;
  int nbmax = (dimx*dimy)/66;
  (nbmax<7)?nbmax=7:0;
  
  if (count < nbmax)
    {
      this->rfork();
      unblockfeed();
      while (pid == -1)
        {
	  if (!(pid = fork()))
	    {
	      Client client(port, team, ip, count+1);
	      client.loop();
	      exit(0);
	    }
	}
    }
  else
    unblockfeed();
}

bool Client::there_is_in_inventory(std::string obj, int n)
{
  std::string inv;
  inventaire(&inv);
  int i;
  int nbr;

  i = inv.find(obj);
  nbr = atoi((inv.c_str()) + (i + obj.length()));
  if (nbr >= n)
    return true;
  return false;
}

void Client::find(std::string obj, int n)
{
  std::string buf;
  std::vector<std::string> *vu;
  bool ok;

  while (!there_is_in_inventory(obj, n) && !called)
    {
      voir(&buf);
      vu = str_to_wordtab2(buf.c_str(), ',');
      ok = false;
      for (unsigned int u = 0; (*vu)[u] != "end" && !ok; ++u)
        {
          if ((*vu)[u].find(obj) != (*vu)[u].npos)
            {
              go_to(tab[u].x, tab[u].y);
              prend(obj);
              ok = true;
            }
        }
      if (!ok)
	go_to(lvl,0);
      delete vu;
    }
}

void Client::vider_case()
{
  if (!called)
    {
      while (prend("nourriture"));
      while (prend("linemate"));
      while (prend("deraumere"));
      while (prend("mendiane"));
      while (prend("phiras"));
      while (prend("thystame"));
      while (prend("sibur"));
    }
}

void Client::make_a_team(int nb)
{
  std::string str;
  int ret;

  member = 0;
  while (!sujets.empty())
    sujets.pop_back();
  broadcast(int_to_str(count) + "/" + team_ + "need" + int_to_str(lvl));
  if (called)
    {
      while (!sujets.empty())
	sujets.pop_back();
      broadcast(int_to_str(count) + "/" + team_ + "STOP" + int_to_str(lvl));
      broadcast(int_to_str(count) + "/" + team_ + "Go" + "1");
      if (!called)
	make_a_team(nb);
    }
  else
    {
      while (sujets.size() < (unsigned int)nb && !called)
	{

	  broadcast(int_to_str(count) + "/" + team_ + "need" + int_to_str(lvl));
	  FD_ZERO(&cdb);
	  FD_SET(s, &cdb);
	  FD_SET(0, &cdb);
	  if (select(s + 1, &cdb, NULL, NULL, &tv) == -1)
	    std_err("Select failed");
	  if ((ret = FD_ISSET(s, &cdb))> 0)
	    {
	      read_on_socket();	  
	      while (!reqs.empty() && reqs.front()[reqs.front().size() - 1] == '\n')
		{
		  str = reqs.front();
		  if (str.find(team_ + "IMPOSITIONED1/" + int_to_str(count)) != str.npos && (std::find(sujets.begin(), sujets.end(),str_to_int(str.c_str() + 10)) == sujets.end()))
		    {
		      sujets.push_back(str_to_int(str.c_str() + 10));
		      std::cout << count << " a decouvert "<< sujets.back() << "pour lvl " << lvl << " il en faut " << nb <<std::endl;
		    }
		  else if (str.find(team_ + "need" + int_to_str(lvl)) && str_to_int(str.c_str() + 10) < count)
		    {
		      called = true;
		      master = str_to_int(str.c_str() + 10);
		    }
		  else if (called && str.find(int_to_str(master)+"/"+team_ + "STOP" + int_to_str(lvl)) != str.npos)
		    appel.set(0, 0);
		  else if (called && str.find(int_to_str(master) + "/" + team_ + "Go") != str.npos)
		    {
		      called = false;
		      master = -1;
		    }
		  reqs.pop_front();
		}
	    }
	  else if (ret < 0)
	    std_err("Something happened...");
	}
      if (lvl == 4 && !called)
	{
	  std::cout << count << "  " << sujets.size() <<std::endl;
	  for (unsigned int i= 0; i < sujets.size(); ++i)
	    std::cout << count<<"final sujvlvl"<< lvl << "  " << sujets[i] <<std::endl;
	}
      if (called)
	{
	  while (!sujets.empty())
	    sujets.pop_back();
	  broadcast(int_to_str(count) + "/" + team_ + "STOP" + int_to_str(lvl));
	  broadcast(int_to_str(count) + "/" + team_ + "Go" + "1");
	  std::cout << count << "my lvl "<< lvl <<"  master" << master<< std::endl;
	  if (!called)
	    make_a_team(nb);
	}
    }
}

int Client::is_guys(int nb)
{
  std::string buf;
  std::vector<std::string> *vu;
  int count = -1;

  voir(&buf);
  vu = str_to_wordtab2(buf.c_str(), ',');
  for (unsigned int i = 0; (*vu)[0][i] != '\0'; ++i)
    {
      if ((*vu)[0][i] == 'j')
        count++;
    }
  delete vu;
  return (nb - count);
}

void Client::guider_la_team(int nb)
{
  std::string s;

  diriging = true;
  member = 0;
  broadcast(int_to_str(count) + "/" + team_ + "need" + int_to_str(lvl));
  while (member < nb)
    {
      read_on_socket();
      while (!reqs.empty() && reqs.front()[reqs.front().size() - 1] == '\n')
	{
	  s = reqs.front();
	  if (s.find(team_ + "IMPOSITIONED1/" + int_to_str(count)) != s.npos && (std::find(sujets.begin(), sujets.end(),str_to_int(s.c_str() + 10)) != sujets.end()))
	    ++member;
	  reqs.pop_front();
	}
    }
  member = 0;
}

void Client::want_guys(int nb)
{
  int manque;

  if (!called)
    {
      manque = is_guys(nb);

      if (manque > 0 && !diriging)
	{
	  make_a_team(nb);
	  called == false ? diriging = true : diriging = false;
	}
      else if (manque < 0 && !diriging)
	{
	  expulse();
	  want_guys(nb);
	  return ;
	}
      
      while (!called && (manque = is_guys(nb)) > 0)
        guider_la_team(nb);
      if (manque < 0 && diriging)
	expulse();
      if (!called)
	broadcast(int_to_str(count) + "/" + team_ + "STOP" + int_to_str(lvl));
    }
}

void Client::go_position()
{
  std::string s;

  direction.set(0,0);
  while (called)
    {
      appel.set(-42,-42);
      broadcast(int_to_str(count) + "/" + team_ + "IMPOSITIONED1/" + int_to_str(master) + "/" + int_to_str(lvl));
      while (appel.x == -42 && called)
	{
	  read_on_socket();
	  while (!reqs.empty() && reqs.front()[reqs.front().size() - 1] == '\n')
	    {
	      s = reqs.front();
	      if (s.find(int_to_str(master) + "/" + team_ + "need" + int_to_str(lvl)) != s.npos)
		appel.set(dir[s[8] - 48].x, dir[s[8] - 48].y);
	      else if (s.find(int_to_str(master)+"/"+team_ + "STOP" + int_to_str(lvl)) != s.npos)
		appel.set(0, 0);
	      else if (s.find(int_to_str(master) + "/" + team_ + "Go") != s.npos)
		called = false;
	      else if (s.find("niveau") != reqs.front().npos)
		lvl++;
	      reqs.pop_front();
	    }
	}
      if (called)
	go_to(appel.x, appel.y);
    }
  appel.set(0,0);
  master = -1;
}

void Client::feed()
{
  std::string buf;
  std::vector<std::string> *vu;
  bool ok;

  for (int i = 0; i < 100 && !called; ++i)
    {
      voir(&buf);
      vu = str_to_wordtab2(buf.c_str(), ',');
      ok = false;
      for (unsigned int u = 0; (*vu)[u] != "end" && !ok; ++u)
        {
          if ((*vu)[u].find("nourriture") != (*vu)[u].npos)
            {
              direction.set(tab[u].x, tab[u].y);
              i += go_to();
              prend("nourriture");
              ++i;
              ok = true;
            }
        }
      if (!ok)
        {
          direction.set(lvl,0);
          i += go_to();
        }
      delete vu;
    }
}


void Client::lvl2()
{

  while (lvl == 1)
    {
      find("nourriture", 20);
      find("linemate");
      vider_case();
      pose("linemate");
      incantation();
    }
}

void Client::lvl3()
{
  feed();
  while (lvl == 2 && !called)
    {
      find("linemate");
      find("deraumere");
      find("sibur");
      want_guys();
      vider_case();
      if (!called)
	pose("linemate");
      if (!called)
	pose("sibur");
      if (!called)
	pose("deraumere");
      if (!called && incantation())
        {
          broadcast(int_to_str(count) + "/" + team_ + "Go" + "1");
          while (!sujets.empty())
            sujets.pop_back();
        }
    }
  diriging = false;
}

void Client::lvl4()
{
  feed();
  while (lvl == 3 && !called)
    {
      find("linemate",2);
      find("sibur");
      find("phiras",2);
      want_guys();
      vider_case();
      if (!called)
	pose("linemate");
      if (!called)
	pose("linemate");
      if (!called)
	pose("sibur");
      if (!called)
	pose("phiras");
      if (!called)
	pose("phiras");
      if (!called && incantation())
	{
	  broadcast(int_to_str(count) + "/" + team_ + "Go" + "1");
	  while (!sujets.empty())
	    sujets.pop_back();
	}
    }
  diriging = false;
}

void Client::lvl5()
{
  feed();
  while (lvl == 4 && !called)
    {
      find("linemate");
      find("deraumere");
      find("sibur",2);
      find("phiras");
      want_guys(3);
      vider_case();
      if (!called)
	pose("linemate");
      if (!called)
	pose("deraumere");
      if (!called)
	pose("sibur");
      if (!called)
	pose("sibur");
      if (!called)
	pose("phiras");
      if (!called && incantation())
	{
	  broadcast(int_to_str(count) + "/" + team_ + "Go" + "1");
	  while (!sujets.empty())
	    sujets.pop_back();
	  end = true;
	}
    }
  diriging = false;
  if (lvl == 5)
    end = true;
}

void Client::loop()
{  
  go_new(port_, team_, ip_);
  lvl2();
  std::cout << "je suis " << count << " lvl 2 ."<< std::endl;
  while (lvl < 8 && !end)
    {
      std::cout << "je suis "<< count << " dans la boucle"<< std::endl;
      lvl3();
      lvl4();
      lvl5();
      if (called)
	go_position();
    }
  std::cout << count << " lvl " <<lvl<< std::endl;
  while (1)
    unblockfeed();
}

