##
## Makefile for serveur zappy in /home/mille_j/zappy/serveur
## 
## Made by John Mille
## Login   <mille_j@epitech.net>
## 
## Started on  Fri Jun 10 19:22:25 2011 John Mille
## Last update Sun Jul 10 11:06:46 2011 john mille
##

NAME		=		serveur

SRCDIR		=		./src/
HDDIR		=		./include/
LDDIR		=		./lib/
BUILD		=		$(SRCDIR)/build/
INCANT		=		$(SRCDIR)/incantation/
NETWORK		=		$(SRCDIR)/networking/
EXEC_ACTIONS	=		$(SRCDIR)exec_actions/
RFC_GRAPH	=		$(SRCDIR)/rfc_graph/
RFC_PLAYER	=		$(SRCDIR)rfc_player/
TOOLS		=		./tools/
ZAPPY_MAIN	=		$(SRCDIR)/zappy_main/

SRCS		=		$(LDDIR)my_getnbr.c			\
				$(LDDIR)my_memset.c			\
				$(LDDIR)my_put_tools.c			\
				$(LDDIR)my_strcat.c			\
				$(LDDIR)my_strcmp.c			\
				$(LDDIR)my_strcpy.c			\
				$(LDDIR)my_strdup.c			\
				$(LDDIR)my_strlen.c			\
				$(LDDIR)my_xfree.c			\
				$(LDDIR)my_xmalloc.c			\
				$(LDDIR)tab_tools.c			\
				$(LDDIR)tab_functions.c			\
				$(TOOLS)tools_chars.c			\
				$(TOOLS)chars_specials.c		\
				$(TOOLS)tools_teams.c			\
				$(TOOLS)tools.c				\
				$(TOOLS)time_diff.c			\
				$(TOOLS)random_functions.c		\
				$(TOOLS)my_xfunctions.c			\
				$(TOOLS)my_xfunctions_network.c		\
				$(TOOLS)my_xfunctions_network_2.c	\
				$(BUILD)check_options.c			\
				$(BUILD)net_setters.c			\
				$(BUILD)map_setters.c			\
				$(BUILD)build_map.c			\
				$(BUILD)build_teams.c			\
				$(BUILD)build_zappy.c			\
				$(NETWORK)send_datas.c			\
				$(NETWORK)init_net.c			\
				$(NETWORK)gere_clients.c		\
				$(NETWORK)loop.c			\
				$(NETWORK)accept_client.c		\
				$(NETWORK)check_clients.c		\
				$(NETWORK)check_death.c			\
				$(NETWORK)check_team.c			\
				$(NETWORK)check_incants.c		\
				$(RFC_GRAPH)rfc_graph_parsing.c		\
				$(RFC_GRAPH)graph_first_connect.c	\
				$(RFC_GRAPH)rfc_graph_bct.c		\
				$(RFC_GRAPH)rfc_graph_ebo.c		\
				$(RFC_GRAPH)rfc_graph_edi.c		\
				$(RFC_GRAPH)rfc_graph_eht.c		\
				$(RFC_GRAPH)rfc_graph_enw.c		\
				$(RFC_GRAPH)rfc_graph_mct.c		\
				$(RFC_GRAPH)rfc_graph_msz.c		\
				$(RFC_GRAPH)rfc_graph_pbc.c		\
				$(RFC_GRAPH)rfc_graph_pdi.c		\
				$(RFC_GRAPH)rfc_graph_pdr.c		\
				$(RFC_GRAPH)rfc_graph_pex.c		\
				$(RFC_GRAPH)rfc_graph_pfk.c		\
				$(RFC_GRAPH)rfc_graph_pgt.c		\
				$(RFC_GRAPH)rfc_graph_pic.c		\
				$(RFC_GRAPH)rfc_graph_pie.c		\
				$(RFC_GRAPH)rfc_graph_pin.c		\
				$(RFC_GRAPH)rfc_graph_plv.c		\
				$(RFC_GRAPH)rfc_graph_pnw.c		\
				$(RFC_GRAPH)rfc_graph_ppo.c		\
				$(RFC_GRAPH)rfc_graph_sbp.c		\
				$(RFC_GRAPH)rfc_graph_seg.c		\
				$(RFC_GRAPH)rfc_graph_sgt.c		\
				$(RFC_GRAPH)rfc_graph_smg.c		\
				$(RFC_GRAPH)rfc_graph_sst.c		\
				$(RFC_GRAPH)rfc_graph_suc.c		\
				$(RFC_GRAPH)rfc_graph_tna.c		\
				$(RFC_GRAPH)str_to_parser.c		\
				$(RFC_PLAYER)rfc_player_parsing.c	\
				$(RFC_PLAYER)rfc_player_avance.c	\
				$(RFC_PLAYER)rfc_player_right.c		\
				$(RFC_PLAYER)rfc_player_fork.c		\
				$(RFC_PLAYER)rfc_player_left.c		\
				$(RFC_PLAYER)rfc_player_invent.c	\
				$(RFC_PLAYER)rfc_player_connect_nbr.c	\
				$(RFC_PLAYER)rfc_player_see.c		\
				$(RFC_PLAYER)rfc_player_see_func_1.c	\
				$(RFC_PLAYER)rfc_player_see_func_2.c	\
				$(RFC_PLAYER)rfc_player_see_dirs_func.c	\
				$(RFC_PLAYER)rfc_player_prend.c		\
				$(RFC_PLAYER)rfc_player_pose.c		\
				$(RFC_PLAYER)rfc_player_broadcast.c	\
				$(RFC_PLAYER)rfc_player_incantation.c	\
				$(RFC_PLAYER)rfc_player_expulse.c	\
				$(RFC_PLAYER)broadcast.c		\
				$(RFC_PLAYER)add_ressource.c		\
				$(RFC_PLAYER)put_ressource.c		\
				$(INCANT)check_can_incant.c		\
				$(INCANT)incant_end.c			\
				$(INCANT)create_incantation.c		\
				$(EXEC_ACTIONS)actions_tools.c		\
				$(ZAPPY_MAIN)destroy_zappy.c		\
				$(ZAPPY_MAIN)zappy.c


OBJS		=		$(SRCS:.c=.o)
CC		=		/usr/bin/gcc
CFLAGS		=		-W -Wall -Wextra -g3
HDFLAGS		+=		-I$(HDDIR)

RM		=		rm -f
ECHO		=		echo -e
TAG		=		etags

NORME		=		/u/all/astek/public/norme/norme -nocheat

$(NAME)		: $(OBJS)
		@$(CC) $(CFLAGS) $(HDFLAGS) -o $(NAME) $(OBJS)
		@$(ECHO) '\033[0;32m> Compiled Without Error\033[0m'

clean		:
		-@$(RM) $(OBJS)
		-@$(RM) *~
		-@$(RM) #*#
		@$(ECHO) '\033[0;35m> Directory cleaned\033[0m'

all		: $(NAME)

norme		:
		$(NORME) $(SRCS)

fclean		: clean
		-@$(RM) $(NAME)
		@$(ECHO) '\033[0;35m> Remove executable\033[0m'

re		: fclean all

.PHONY		: all clean re fclean tag norme

tag		:
		-@$(TAG) $(SRCS)
		@$(ECHO) '\033[0;32m> TAGS Done\033[0m'

.c.o		:
		$(CC) $(CFLAGS) $(HDFLAGS) -c $< -o $@

