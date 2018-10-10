/*
** cmd_parsing.h for cmd parsing for zappy in /home/mille_j/zappy/serveur/src/cmd_line_parsing
**
** Made by John Mille
** Login   <mille_j@epitech.net>
**
** Started on  Sat Jun 11 04:54:32 2011 John Mille
** Last update Wed Jun 22 16:35:02 2011 john mille
*/

#ifndef			__CMD_PARSING_H__
# define		__CMD_PARSING_H__


#define			USAGE_OPTION_1		"-p option needs one value from 1024 to 65535\n"
#define			USAGE_OPTION_2		"-x option needs one value from 10 to 4096\n"
#define			USAGE_OPTION_3		"-y option needs one value from 10 to 4096\n"
#define			USAGE_OPTION_4		"-n option needs one or more values separated by ' '\n"
#define			USAGE_OPTION_5		"-c option needs one positive value from 1 to 1024\n"
#define			USAGE_OPTION_6		"-t option needs one positive value from 0.001 to 100\n"

typedef struct		s_options
{
  int			id;
  int			value_min;
  int			value_max;
  char			*flag;
  char			*usage;
  int			(*func)(char **argv, int opt, int i);
}			t_options;

int			man(void);
int			check_options(char **argv, int opt, int i);
int			check_teams(char **argv, int opt, int i);

#endif			/* !__CMD_PARSING_H__ */
