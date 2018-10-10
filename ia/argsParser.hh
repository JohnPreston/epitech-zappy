/* 
 * File:   argsParser.h
 * Author: brigin_i
 *
 * Created on July 5, 2011, 5:19 PM
 */

#ifndef ARGSPARSER_H
#define	ARGSPARSER_H

#include <string>

class argsParser {
public:
    argsParser(int ac, char **av);
    virtual ~argsParser();
    int getPort();
    std::string& getTeam();
    std::string& getIP();
private:
    std::string  team;
    std::string  ip;
    int port;
};

#endif	/* ARGSPARSER_H */

