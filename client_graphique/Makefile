##
## Makefile for testage in /home/el-out_y//test/gdl
## 
## Made by youssef el-outmani
## Login   <el-out_y@epitech.net>
## 
## Started on  Wed May 25 17:17:35 2011 youssef el-outmani
## Last update Sat Jul  9 08:46:04 2011 youssef el-outmani
##

NAME		=	VisuZappy

DIR		=	src/

SRC		=	$(DIR)main.cpp		\
			$(DIR)Socket.cpp	\
			$(DIR)Monitor.cpp	\
			$(DIR)Camera.cpp

SRC2		=	$(DIR)get_next_line.cpp

OBJ		=	$(SRC:.cpp=.o)

OBJ2		=	$(SRC2:.cpp=.o)

CXXFLAGS	+=	-W -Wall -Werror

RM		=	rm -f

CXX		=	g++ -g

INCLUDE		+=	-I/afs/epitech.net/users/labos/gamelab/public/include -I./include/

LDFLAGS		=	-L/afs/epitech.net/users/labos/gamelab/public/lib -Wl,--rpath=/afs/epitech.net/users/labos/gamelab/public/lib -lgdl_gl -lGL -lGLU -lm


$(NAME)		: $(OBJ) $(OBJ2)
		$(CXX) -o $(NAME) $(OBJ) $(OBJ2) $(LDFLAGS)

all		: $(NAME)

clean		:
		$(RM) $(OBJ)

fclean		: clean
		$(RM) $(NAME)

re		: fclean all

.cpp.o		:
		$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

.c.o		:
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
