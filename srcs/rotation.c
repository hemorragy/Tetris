/*
** key.c for key in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Mon Mar  7 11:55:22 2016 Loïs
** Last update Sun Mar 20 22:49:00 2016 Loïs
*/

#include "tetris.h"

static void	get_sidex(const t_mino *mino, t_info *info, bool mod)
{
  int		check;
  int		direction;

  check = (g_rotate % 2 == 0) ? mino->width - mino->height :
    mino->height - mino->width;
  direction = (check > 0) ? 0 : 1;
  if (mod == 0)
    {
      info->sidex = info->sidex + ((mino->height - mino->width) / 2);
      if ((mino->height - mino->width) % 2 != 0)
	info->sidex = (g_rotate % 2 + direction == 1) ?
	  info->sidex + 1 : info->sidex - 1;
    }
  else
    {
      if ((mino->height - mino->width) % 2 != 0)
	info->sidex = (g_rotate % 2 + direction == 1) ?
	  info->sidex - 1 : info->sidex + 1;
      info->sidex = info->sidex - ((mino->height - mino->width) / 2);
    }
}

static void	go_on(const t_mino *mino, const t_opt *opts,
		      const t_info *info, int **tray)
{
  int		i;
  int		idx;

  i = 0;
  while (i < opts->map_row + info->max)
    {
      idx = -1;
      while (++idx < opts->map_col)
	if (tray[i][idx] == -1)
	  tray[i][idx] = 0;
      ++i;
    }
  i = info->sidey;
  while (i < info->sidey + mino->height)
    {
      idx = info->sidex;
      while (idx < mino->width + info->sidex)
	{
	  if (mino->piece[g_rotate][i - info->sidey][idx - info->sidex] == 1)
	    tray[i][idx] = mino->color;
	  ++idx;
	}
      ++i;
    }
}

static void	come_back(t_mino *mino, t_info *info, int **tray)
{
  int		tmp;
  int		i;
  int		idx;

  g_rotate = (g_rotate == 0) ? 3 : g_rotate - 1;
  get_sidex(mino, info, 1);
  info->sidey = info->sidey - (mino->width - mino->height);
  tmp = mino->height;
  mino->height = mino->width;
  mino->width = tmp;
  i = info->sidey;
  while (i < info->sidey + mino->height)
    {
      idx = info->sidex;
      while (idx < mino->width + info->sidex)
	{
	  if (tray[i][idx] == -1)
	    tray[i][idx] = mino->color;
	  ++idx;
	}
      ++i;
    }
}

static bool	if_possible(const t_mino *mino, const t_opt *opts,
			    const t_info *info, const int **tray)
{
  int		i;
  int		idx;

  if (info->sidex < 0 || info->sidex >= opts->map_col)
    return (0);
  i = info->sidey;
  while (i < info->sidey + mino->height)
    {
      idx = info->sidex;
      while (idx < mino->width + info->sidex)
	{
	  if (mino->piece[g_rotate][i - info->sidey][idx - info->sidex] == 1 &&
	      tray[i][idx] > 10)
	    return (0);
	  ++idx;
	}
      ++i;
    }
  return (1);
}

void	the_rotate(t_mino *mino, const t_opt *opts, t_info *info, int **tray)
{
  int	i;
  int	idx;
  int	tmp;

  i = info->sidey;
  while (i < info->sidey + mino->height)
    {
      idx = info->sidex - 1;
      while (++idx < mino->width + info->sidex)
	if (tray[i][idx] > 0 && tray[i][idx] < 10)
	  tray[i][idx] = -1;
      ++i;
    }
  tmp = mino->height;
  mino->height = mino->width;
  mino->width = tmp;
  info->sidey = info->sidey + (mino->width - mino->height);
  get_sidex(mino, info, 0);
  g_rotate = (g_rotate == 3) ? 0 : g_rotate + 1;
  if (if_possible(mino, opts, info, (const int **)tray))
    go_on(mino, opts, info, tray);
  else
    come_back(mino, info, tray);
}
