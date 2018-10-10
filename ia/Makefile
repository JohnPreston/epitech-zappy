##
## Makefile for  in /home/periph_a//zappi
## 
## Made by alexandre periphanos
## Login   <periph_a@epitech.net>
## 
## Started on  Fri Jun 17 16:36:55 2011 alexandre periphanos
## Last update Sun Jul 10 11:28:15 2011 john mille
##

SRCS_CLIENT	= client.cpp			\
		  stream_manip.cpp		\
		  main.cpp			\
		  str_to_wordtab.cpp		\
		  str_to_wordtab2.cpp		\
		  argsParser.cpp

CC		= g++

OBJS		= $(SRCS_CLIENT:.cpp=.o)

CFLAGS		+= -W -Werror -Wall
NAME_CLIENT	= client_zappy


all		: $(NAME_CLIENT)
$(NAME_CLIENT)	: $(OBJS)
		  $(CC) $(OBJS) -o $(NAME_CLIENT) $(CFLAGS)
clean		:
		  rm -rf *.o
		  rm -rf *~
		  rm -rf *#

fclean		: clean
		  rm -f $(NAME_CLIENT)

re		: fclean all