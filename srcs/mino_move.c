/*
** gest_mino.c for gest_mino in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Mon Feb 29 14:37:46 2016 Loïs
** Last update Sun Mar 20 22:34:24 2016 Loïs
*/

#include <stdlib.h>
#include "tetris.h"

static int	check_tray_case(const t_mino *mino, const t_opt *opts,
				t_info *info, const int **tray)
{
  int		i;
  int		idx;
  bool		check;

  if (info->sidey + mino->height >= opts->map_row + info->max)
    return ((info->sidey + mino->height - (opts->map_row + info->max)) + 1);
  ++info->sidey;
  check = 0;
  i = info->sidey - 1;
  while (++i < info->sidey + mino->height)
    {
      idx = info->sidex - 1;
      while (++idx < info->sidex + mino->width)
	{
	  if (tray[i][idx] > 10 &&
	      (tray[i - 1][idx] > 0 && tray[i - 1][idx] < 10))
	    return (1);
	  check = (tray[i - 1][idx] > 0 && tray[i - 1][idx] < 10) ?
	    1 : check;
	}
    }
  if (check == 0)
    --info->sidey;
  return ((check == 0) ? 2 : 0);
}

static bool	down_collision(t_mino *mino, const t_info *info, int **tray)
{
  int		i;
  int		idx;

  i = info->sidey - 1;
  while (i < info->sidey + mino->height)
    {
      idx = info->sidex;
      while (idx < info->sidex + mino->width)
	{
	  if (tray[i][idx] > 0 && tray[i][idx] < 10)
	    tray[i][idx] = tray[i][idx] + 10;
	  ++idx;
	}
      ++i;
    }
  if (g_rotate % 2 == 1)
    {
      idx = mino->width;
      mino->width = mino->height;
      mino->height = idx;
    }
  g_rotate = 0;
  return (0);
}

bool	go_down(t_mino *mino, const t_opt *opts, t_info *info, int **tray)
{
  int	i;
  int	idx;

  if ((i = check_tray_case(mino, opts, info, (const int **)tray)) == 1)
    return (down_collision(mino, info, tray));
  else if (!i)
    {
      i = info->sidey + mino->height;
      while (i >= info->sidey)
	{
	  idx = info->sidex;
	  while (idx < info->sidex + mino->width)
	    {
	      if (tray[i - 1][idx] > 0 && tray[i - 1][idx] < 10)
		{
		  tray[i][idx] = tray[i - 1][idx];
		  tray[i - 1][idx] = 0;
		}
	      ++idx;
	    }
	  --i;
	}
      return (1);
    }
  return (0);
}

bool	place_piece_center(const t_mino *mino, const t_opt *opts,
			   t_info *info, int **tray)
{
  int	idx;
  int	i;

  idx = (opts->map_col % 2 == 0) ? opts->map_col / 2 - 1 : opts->map_col / 2;
  info->sidex = (mino->width % 2 == 0) ? mino->width / 2 - 1 : mino->width / 2;
  info->sidex = idx - info->sidex;
  info->sidey = info->max - mino->height;
  i = info->sidey;
  while (i < mino->height + info->sidey)
    {
      idx = 0;
      while (idx < mino->width)
	{
	  if (mino->piece[0][i - info->sidey][idx] == 1)
	    {
	      if (tray[i][info->sidex + idx] > 0)
		return (0);
	      else
		tray[i][info->sidex + idx] = mino->color;
	    }
	  ++idx;
	}
      ++i;
    }
  return (1);
}

t_mino	*take_new_piece(t_mino *mino)
{
  int	i;

  i = 1;
  mino = mino->first->next;
  while (mino != mino->first)
    {
      mino = mino->next;
      ++i;
    }
  i = rand() % i;
  while (i > 0)
    {
      mino = mino->next;
      --i;
    }
  while (mino->piece == NULL)
    mino = mino->next;
  return (mino);
}
