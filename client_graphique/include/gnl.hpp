/*
** get_next_line.h for GNL in /u/all/ketata_y/cu/rendu/c/get_next_line
** 
** Made by yanis ketata
** Login   <ketata_y@epitech.net>
** 
** Started on  Mon May 10 10:57:32 2010 yanis ketata
** Last update Sun May 23 17:03:34 2010 yanis ketata
*/

#ifndef	__GET_NEXT_LINE_H__
# define __GET_NEXT_LINE_H__

# define BUFF_SIZE 2

typedef struct		s_struct
{
  char			*tab;
  int			nb;
  int			pos;
  int			cpt;
}			t_struct;

char			*get_next_line(const int fd);

#endif			/*__GET_NEXT_LINE_H__*/
