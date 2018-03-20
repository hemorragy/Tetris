/*
** stock_tetrimino.c for stock_tetrimino in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Wed Feb 24 18:31:45 2016 Loïs
** Last update Sun Mar 20 23:27:35 2016 Loïs
*/

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "tetris.h"
#include "my.h"

static bool	fill_form(bool *piece, t_mino *mino, const char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0 && i < mino->width)
    {
      if (str[i] == ' ')
	piece[i] = 0;
      else if (str[i] == '*')
	piece[i] = 1;
      else
	return (1);
      ++i;
    }
  if (i < mino->width)
    while (i < mino->width)
      {
	piece[i] = 0;
	++i;
      }
  return (0);
}

static bool	fill_line_1(t_mino *mino, char *str)
{
  int		i;
  int		idx;

  idx = 0;
  i = find_space(str, &idx);
  if (my_str_nisnum(str, i))
    mino->width = my_getnbr(str);
  else
    return (1);
  idx = (str[idx] != 0) ? idx + 1 : idx;
  i = find_space(str, &idx);
  if (my_str_nisnum(str + idx - i, i))
    mino->height = my_getnbr(str + idx - i);
  else
    return (1);
  idx = (str[idx] != 0) ? idx + 1 : idx;
  i = find_space(str, &idx);
  if (my_str_nisnum(str + idx - i, i))
    mino->color = my_getnbr(str + idx - i);
  else
    return (1);
  if (str[idx] == 0 && i != 0 && (mino->color > 0 && mino->color < 8))
    return (0);
  return (1);
}

static void	set_link_pieces(t_mino *mino, int fd)
{
  char		*tmp;
  int		i;

  i = 0;
  mino->piece = xmalloc(sizeof(bool **) * 4);
  mino->piece[0] = xmalloc(sizeof(bool *) * mino->height);
  while ((tmp = get_next_line(fd)))
    {
      if (i < mino->height)
	{
	  mino->piece[0][i] = xmalloc(sizeof(bool) * mino->width);
	  if (my_strlen(tmp) - end_space(tmp) > mino->width ||
	      fill_form(mino->piece[0][i], mino, tmp))
	    {
	      mino->piece = NULL;
	      get_next_line(-1);
	      free(tmp);
	      return ;
	    }
	  free(tmp);
	}
      ++i;
    }
  if (i > mino->height || i < mino->height)
    mino->piece = NULL;
}

void	set_link_value(t_mino *mino, struct dirent *read)
{
  char	*tmp;
  int	fd;

  mino->piece = NULL;
  mino->name = my_strdup(read->d_name);
  mino->name[my_strlen(mino->name) - 10] = 0;
  mino->width = 0;
  mino->height = 0;
  mino->color = 0;
  if ((fd = open(read->d_name, O_RDONLY)) == -1)
    my_error("Error : open error\n");
  if ((tmp = get_next_line(fd)))
    {
      if (fill_line_1(mino, tmp))
	{
	  free(tmp);
	  get_next_line(-1);
	  return ;
	}
      free(tmp);
    }
  set_link_pieces(mino, fd);
  if (close(fd))
    my_error("Error : close function failed\n");
}

bool	creat_link(t_mino *tmp, t_mino *current, int test)
{
  if (test == 0)
    {
      tmp->prev = tmp;
      tmp->first = tmp;
      tmp->next = tmp;
    }
  else
    {
      current->next = tmp;
      tmp->prev = current;
      tmp->first = current->first;
      tmp->next = current->first;
      current->first->prev = tmp;
    }
  return (1);
}
