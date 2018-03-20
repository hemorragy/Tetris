/*
** get_tetrimino.c for get_tetrimino in /home/antoin_g/rendu/Unix/PSU_2015_tetris/srcs
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Mon Feb 22 15:32:21 2016 Loïs
** Last update Sun Mar 20 22:19:41 2016 Loïs
*/

#include <sys/stat.h>
#include <unistd.h>
#include "tetris.h"
#include "my.h"

void	rotate_pieces(t_mino *mino, int i)
{
  int	sizew;
  int	sizeh;
  int	idx;
  int	id;

  while (i < 4)
    {
      sizeh = (i % 2 == 1) ? mino->width : mino->height;
      sizew = (i % 2 == 1) ? mino->height : mino->width;
      mino->piece[i] = xmalloc(sizeof(int *) * sizeh);
      id = 0;
      while (id < sizeh)
	{
	  mino->piece[i][id] = xmalloc(sizeof(int) * sizew);
	  idx = 0;
	  while (idx < sizew)
	    {
	      mino->piece[i][id][idx] = mino->piece[i - 1][sizew - 1 - idx][id];
	      ++idx;
	    }
	  ++id;
	}
      ++i;
    }
}

static bool		if_tetrimino(const char *name)
{
  static const char	tetri[11] = ".tetrimino";
  struct stat		detail;
  int			size;

  if (stat(name, &detail) == -1)
    my_error("Error : stat function failed\n");
  size = my_strlen(name);
  if (!S_ISREG(detail.st_mode) || size < 11 ||
      !my_strcmp(tetri, name + (size - 10)))
    return (0);
  return (1);
}

int	find_space(const char *str, int *idx)
{
  int	i;

  i = 0;
  while (str[*idx] != ' ' && str[*idx] != 0)
    {
      ++*idx;
      ++i;
    }
  return (i);
}

static void	check_all_mino(t_mino *mino, const t_opt *opts)
{
  check_validate_form(mino);
  if (mino->width > opts->map_col || mino->height > opts->map_row)
    {
      free_minos(mino, 1);
      mino->piece = NULL;
    }
  mino = mino->next;
  while (mino != mino->first)
    {
      check_validate_form(mino);
      if (mino->width > opts->map_col || mino->height > opts->map_row)
	{
	  free_minos(mino, 1);
	  mino->piece = NULL;
	}
      mino = mino->next;
    }
}

t_mino		*get_tetrimino(const t_opt *opts)
{
  struct dirent	*read;
  t_mino	*current;
  t_mino	*tmp;
  bool		test;
  DIR		*rep;

  test = 0;
  if (!(rep = opendir("tetriminos")) || chdir("tetriminos"))
    my_error("Error : No directory tetriminos or no access\n");
  while ((read = readdir(rep)))
    {
      if (if_tetrimino(read->d_name))
	{
	  tmp = xmalloc(sizeof(t_mino));
	  test = creat_link(tmp, current, test);
	  set_link_value(tmp, read);
	  current = tmp;
	}
    }
  if (!test)
    my_error("Error : No .tetrimino files\n");
  check_all_mino(tmp->first, opts);
  if (chdir("..") || closedir(rep))
    my_error("Error : Fail to exit tetriminos\n");
  return (tmp->first);
}
