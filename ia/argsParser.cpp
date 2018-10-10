/* 
 * File:   argsParser.cpp
 * Author: brigin_i
 * 
 * Created on July 5, 2011, 5:19 PM
 */

#include <locale>
#include <string>
#include <iostream>
#include <sstream>
#include <getopt.h>
#include <unistd.h>
#include <stdlib.h>
#include <iosfwd>

#include "argsParser.hh"
#include "stream_manip.hh"

argsParser::argsParser(int ac, char **av)
{
    int c = 0;
    extern char *optarg;
    this->ip = "127.0.0.1";
    this->port = 0;
    while ((c = getopt (ac, av, "n:p:h:")) != -1)
    {
        std::string arg(optarg);
        switch (c)
        {
        case 'n' :
            if (arg == "" || arg[0] == '-')
            {
                std::cerr << "team name must not be null" << std::endl;
                exit(0);
            }
            this->team = optarg;
            break;
        case 'p':
            if (arg == "" || arg[0] == '-')
            {
                std::cerr << "port must not be null" << std::endl;
                exit(0);
            }
            this->port = str_to_int2(optarg);
            break;
        case 'h':
            if (arg == "" || arg[0] == '-')
            {
                std::cerr << "IP must not be null" << std::endl;
                exit(0);
            }
            this->ip = optarg;
            break;
        default:
            std::cerr << "Unknown option" << std::endl;
        }
    }
    if (port == 0)
    {
        std::cerr << "Please, enter the port number" << std::endl;
        exit(0);
    }
    std::cout << "team " << this->team << std::endl;
    std::cout << "port " << this->port << std::endl;
    std::cout << "ip " << this->ip << std::endl;
}

int argsParser::getPort()
{
    return this->port;
}

std::string& argsParser::getTeam()
{
    return this->team;
}

std::string& argsParser::getIP()
{
    return this->ip;
}

argsParser::~argsParser()
{
}

