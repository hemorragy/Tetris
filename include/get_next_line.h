/*
** get_next_line.h for get_next_line in /home/antoin_g/rendu/C_prog_elem/CPE_2015_getnextline
**
** Made by Loïs Antoine
** Login   <antoin_g@Lois-Labtop>
**
** Started on  Mon Jan  4 14:34:27 2016 Loïs Antoine
** Last update Mon Mar  7 20:54:55 2016 Loïs
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

#ifndef READ_SIZE
# define READ_SIZE (256)
#endif /* !READ_SIZE */

typedef struct	s_gnl
{
  char		*temp;
  char		*line;
  int		tmp;
  int		test;
}		t_gnl;

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
