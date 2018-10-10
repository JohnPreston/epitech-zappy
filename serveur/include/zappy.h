/*
** zappy.h for zappy in /home/mille_j/zappy/serveur
**
** Made by John Mille
** Login   <mille_j@epitech.net>
**
** Started on  Sat Jun 11 10:38:14 2011 John Mille
** Last update Sat Jul  9 11:53:02 2011 john mille
*/

#ifndef				__ZAPPY_H__
# define			__ZAPPY_H__

#include			<sys/socket.h>
#include			<netinet/in.h>
#include			<arpa/inet.h>
#include			<sys/types.h>
#include			<sys/time.h>
#include			<time.h>
#include			<netdb.h>

# define			INIT_FAILURE		0
# define			INIT_SUCCESS		1

# define			FRONT			1
# define			FRONT_RIGHT		2
# define			RIGHT			3
# define			BACK_RIGHT		4
# define			BACK			5
# define			BACK_LEFT		6
# define			LEFT			7
# define			FRONT_LEFT		8

# define			NORTH			1
# define			EAST			2
# define			SOUTH			3
# define			WEST			4

# define			WELCOME			"BIENVENUE\n"

typedef int			PORT;
typedef int			FLAG;
typedef int			SOCKET;
typedef struct timeval		TIME_VAL;
typedef struct	sockaddr	SOCKADDR;
typedef struct	sockaddr_in	SOCKADDR_IN;
typedef struct	protoent	PROTO;
typedef socklen_t		SOCKLEN;

typedef struct			s_case
{
  int				x;
  int				y;
  int				nourriture;
  int				linemate;
  int				deraumere;
  int				sibur;
  int				mendiane;
  int				phiras;
  int				thystame;
}				t_case;

typedef struct			s_invent
{
  int				nourriture;
  int				linemate;
  int				deraumere;
  int				sibur;
  int				mendiane;
  int				phiras;
  int				thystame;
}				t_invent;

typedef struct			s_map
{
  int				map_x;
  int				map_y;
  int				time;
  t_case			**cases;
  float				time_unit;
}				t_map;

typedef struct			s_chars
{
  int				id;
  int				is_egg;
  int				is_ghost;
  int				pos_x;
  int				pos_y;
  int				dir;
  int				level;
  SOCKET			s_chars;
  struct timeval		*eat;
  struct s_actions		*actions;
  struct s_chars       		*next;
  t_invent			*invent;
}				t_chars;

typedef struct			s_teams
{
  int				id;
  char				*name;
  unsigned int			nb_members;
  unsigned int			max_members;
  unsigned int			max_members_init;
  t_chars			*chars;
  struct s_teams		*next;
}				t_teams;

typedef struct			s_net
{
  unsigned int			max_clients;
  PORT				port;
  SOCKET			s_serv;
  SOCKET			s_client;
  SOCKET			s_max;
  SOCKADDR_IN			sin_serv;
  SOCKADDR_IN			cin_client;
  SOCKLEN			sin_size;
  SOCKLEN			cin_size;
  FLAG				opt;
  int				*fd;
  PROTO				*proto;
  fd_set			_r;
  fd_set			_w;
  struct timeval		_t;
}				t_net;

typedef	struct			s_zappy
{
  unsigned int			nb_clients;
  unsigned int			id_client;
  unsigned int			id_client_ok;
  unsigned int			nb_incant;
  int				nb_teams;
  struct timeval		*time;
  t_map				*map;
  t_net				*net;
  t_teams			*teams;
}				t_zappy;

typedef struct			s_actions
{
  int				nb_actions;
  char				*cmd;
  char				*res;
  struct timeval		*time;
  t_chars			*c;
  t_teams			*t;
  t_zappy			*z;
  void				(*func)(t_zappy *z, t_teams *t, t_chars *c, char *cmd);
  struct s_actions		*last;
  struct s_actions		*next;
}				t_actions;

typedef struct			s_elevation
{
  int				id;
  int				nb_pl;
  int				nb_li;
  int				nb_de;
  int				nb_si;
  int				nb_me;
  int				nb_ph;
  int				nb_th;
}				t_elevation;

typedef struct			s_options
{
  int				id;
  char				*flag;
  void				(*func)(t_zappy *zappy, char **argv, int i);
}				t_options;

typedef struct			s_map_
{
  int				id;
  char				*name;
  int				(*func)(t_zappy *z, t_chars *c, int x, int y);
}				t_map_;

typedef struct                  s_ressource
{
  int                           id;
  char                          *name;
  void                          (*func)(t_chars *c, t_zappy *z);
}                               t_ressource;

/*****************************************************************************/
/****************************** Setters **************************************/

void				set_map_x(t_zappy *zappy, char **argv, int i);
void				set_map_y(t_zappy *zappy, char **argv, int i);
void				set_net_port(t_zappy *zappy, char **argv, int i);
void				set_max_clients(t_zappy *zappy, char **argv, int i);
void				set_map_time_unit(t_zappy *zappy, char **argv, int i);
void				init_case(t_zappy *zappy, t_case **Case);
void				destroy_zappy(t_zappy *zappy);
void				init_ressource(t_case *Case);
void				build_teams(t_zappy *zappy, char **argv, int i);

int				set_ressource();

t_case				**alloc_map(t_case **Case, t_zappy *zappy);

/*****************************************************************************/
/*****************************************************************************/

int				build(int argc, char **argv, t_zappy *zappy);
int				init_socket(t_zappy *zappy);
int				check_cmd_line(int argc, char **argv);
int				my_xclose(int fd);

/*****************************************************************************/
/****************************** teams tools **********************************/

t_teams				*create_team(char *name, int id, unsigned int max_members);
t_teams				*add_team(t_teams *head, t_teams *new);

/*****************************************************************************/
/****************************** chars tools **********************************/

void				set_eat_time(t_zappy *z, t_chars *new);
void				init_new_char(t_zappy *z, t_chars *to, t_chars *from);
void				move_char(t_teams *to, t_teams *from, t_chars *c);
void				char_takes_ghost(t_zappy *z, t_chars *c, t_chars *ghost);

int				random_dir();
int				random_pos_x(t_map *map);
int				random_pos_y(t_map *map);

t_chars				*create_char(unsigned int id, SOCKET socket);
t_chars				*add_char(t_chars *head, t_chars *new);
t_chars				*delete_char(t_teams *teams, t_chars *to_del, int opt);

/*****************************************************************************/
/****************************** actions tools*********************************/

t_actions			*create_action(void *a, int coeff, struct timeval *time, t_zappy *z, t_teams *t, t_chars *c, char *cmd);
t_actions			*add_action(t_actions *actions, t_actions *new);
t_actions			*depop_action(t_actions *actions);

/*****************************************************************************/
/********************** network x functions ***********************************/

SOCKET				my_xsocket(int domain, int type, int protocol);
int				my_xbind(SOCKET socketfd, SOCKADDR *addr, SOCKLEN addrlen);
int				my_xlisten(SOCKET socket, int backlog);
int				my_xaccept(SOCKET socket, SOCKADDR *addr, SOCKLEN *socklen);
int				my_xconnect(SOCKET socket, SOCKADDR *addr, SOCKLEN len);
int				my_xsetsockopt(SOCKET sock, int level, int optname, void *optval, SOCKLEN optlen);

/******************************************************************************/
/****************************** Main loop functions ***************************/

void				loop(t_zappy *z);
void				add_client(t_zappy *z);
void				gere_client(t_zappy *z, t_teams *t, t_chars *c);
void				check_team(t_zappy *z, t_chars *c, char *name);
void				send_datas(t_zappy *z, t_teams *t, t_chars *c);
void				check_clients(t_zappy *z);
void				check_clients_tasks(t_zappy *z);
void				check_deaths(t_zappy *z);
void				check_incants(t_zappy *z);

/******************************************************************************/
/****************************** graphic functions *****************************/

int				nb_words(char *str);
int				check_client_is_alive(t_chars *c);

char				**str_parser(char *str);

void				graph_first_connect(t_zappy *c);
void				rfc_graph_msz(t_zappy *z, t_teams *t, t_chars *c, char *buff);
void				rfc_graph_bct(t_zappy *z, t_teams *t, t_chars *c, char *buff);
void				rfc_graph_mct(t_zappy *z, t_teams *t, t_chars *c, char *buff);
void				rfc_graph_tna(t_zappy *z, t_teams *t, t_chars *c, char *buff);

void				rfc_graph_mct_serv(t_zappy *z);
void				rfc_graph_msz_serv(t_zappy *z);
void				rfc_graph_bct_serv(t_zappy *z, int i, int j);
void				rfc_graph_tna_serv(t_zappy *z);
void				rfc_graph_sgt_serv(t_zappy *z);

void				rfc_graph_pnw(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_graph_ppo(t_zappy *z, t_teams *t, t_chars *c, char *buff);
void				rfc_graph_plv(t_zappy *z, t_teams *t, t_chars *c, char *buff);
void				rfc_graph_pin(t_zappy *z, t_teams *t, t_chars *c, char *buff);
void				rfc_graph_pdi(t_zappy *z, t_chars *c);
void				rfc_graph_pfk(t_zappy *z, t_chars *c);
void				rfc_graph_pbc(t_zappy *z, t_chars *c, char *msg);
void				rfc_graph_pic(t_zappy *z, t_chars *c);
void				rfc_graph_pdr(t_zappy *z, t_chars *c, int ress);
void				rfc_graph_pgt(t_zappy *z, t_chars *c, int ress);
void				rfc_graph_pie(t_zappy *z, t_chars *c, int res);

void				rfc_graph_pnw_serv(t_zappy *z, t_chars *c);
void				rfc_graph_ppo_serv(t_zappy *z, t_chars *c);
void				rfc_graph_plv_serv(t_zappy *z, t_chars *c);
void				rfc_graph_pin_serv(t_zappy *z);

void				rfc_graph_enw(t_zappy *z, t_chars *c, t_chars *egg);
void				rfc_graph_eht(t_zappy *z, unsigned int id);
void				rfc_graph_ebo(t_zappy *z, unsigned int id);
void				rfc_graph_edi(t_zappy *z, t_chars *c);

void				rfc_graph_sgt(t_zappy *z, t_teams *t, t_chars *c, char *buff);
void				rfc_graph_sst(t_zappy *z, t_teams *t, t_chars *c, char *buff);
void				rfc_graph_suc(SOCKET socket);

void				parser_rfc_graph(t_zappy *z, t_teams *t, t_chars *chars, char *buff);

/*****************************************************************************/
/****************************** players functions ****************************/

void				rfc_player_parsing(t_zappy *z, t_teams *t, t_chars *c, char *cmd);
void				rfc_player_avance(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_right(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_left(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_fork(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_eclose(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_invent(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_connect_nbr(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_see(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_prend(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_pose(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_broadcast(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_incantation(t_zappy *z, t_teams *t, t_chars *c);
void				rfc_player_expulse(t_zappy *z, t_teams *t, t_chars *c);

char				*see_north(t_zappy *z, t_chars *c, int x, int y);
char				*see_south(t_zappy *z, t_chars *c, int x, int y);
char				*see_east(t_zappy *z, t_chars *c, int x, int y);
char				*see_west(t_zappy *z, t_chars *c, int x, int y);
char				*one_case(t_zappy *z, t_chars *c, int x, int y, char *see);

int				there_is_player(t_zappy *z, t_chars *c, int x, int y);
int				there_is_food(t_zappy *z, t_chars *c, int x, int y);
int				there_is_linemate(t_zappy *z, t_chars *c, int x, int y);
int				there_is_deraumere(t_zappy *z, t_chars *c, int x, int y);
int				there_is_sibur(t_zappy *z, t_chars *c, int x, int y);
int				there_is_mendiane(t_zappy *z, t_chars *c, int x, int y);
int				there_is_phiras(t_zappy *z, t_chars *c, int x, int y);
int				there_is_thystame(t_zappy *z, t_chars *c, int x, int y);

int				get_direct(int x1, int y1, int x2, int y2);
int				direct_4_char(int dir, int char_dir);

/****************************************************************************/
/****************************************************************************/

void				init_incant(t_zappy *z, t_teams *t, t_chars *c);
void				check_incant_end(t_zappy *z, t_teams *t, t_chars *c, char *cmd);
void				level_up(t_zappy *z, t_chars *incant);
void				incant_failed(t_zappy *z, t_chars *incant);

int				can_incant(t_zappy *z, t_teams *t, t_chars *c);
int				create_incant(t_zappy *z, t_teams *t, t_chars *c);

/*****************************************************************************/
/****************************** global tools *********************************/

void				dump_teams(t_zappy *z);
void				init_invent(t_invent *i);
void				calc_next_eat(t_map *map, struct timeval *now, struct timeval *time);

int				my_strisnum(char *str);
int				time_is_gone(struct timeval *t2, struct timeval *t1);

struct timeval			*time_to_death(t_map *map, struct timeval *time);

/*****************************************************************************/
/****************************** add_ressource ********************************/

void				add_deraumere(t_chars *c, t_zappy *z);
void				add_sibur(t_chars *c, t_zappy *z);
void				add_mendiane(t_chars *c, t_zappy *z);
void				add_phiras(t_chars *c, t_zappy *z);
void				add_thystame(t_chars *c, t_zappy *z);
void				add_food(t_chars *c, t_zappy *z);
void				add_linemate(t_chars *c, t_zappy *z);

/*****************************************************************************/
/****************************** put_ressource *********************************/

void				put_deraumere(t_chars *c, t_zappy *z);
void				put_sibur(t_chars *c, t_zappy *z);
void				put_mendiane(t_chars *c, t_zappy *z);
void				put_phiras(t_chars *c, t_zappy *z);
void				put_thystame(t_chars *c, t_zappy *z);
void				put_food(t_chars *c, t_zappy *z);
void				put_linemate(t_chars *c, t_zappy *z);

/*****************************************************************************/
/*****************************************************************************/


#endif				/* !__ZAPPY_H__ */
