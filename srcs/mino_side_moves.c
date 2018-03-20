/*
** mino_side_moves.c for tetris in /home/chouik_e/Rendu/xTODO/PSU_2015_tetris
**
** Made by Eddy Chouikha
** Login   <chouik_e@epitech.net>
**
** Started on  Mon Mar 14 17:20:00 2016 Eddy Chouikha
** Last update Sun Mar 20 22:36:15 2016 Loïs
*/

#include "tetris.h"

static bool	check_left_case(const t_mino *mino, const t_info *info,
				const int **tray)
{
  int		y;
  int		x;

  y = info->sidey;
  if (info->sidex == 0)
    return (1);
  while (y < info->sidey + mino->height)
    {
      x = info->sidex;
      while (x < info->sidex + mino->width)
	{
	  if (tray[y][x] > 0 && tray[y][x] < 10 && tray[y][x - 1] > 10)
	    return (1);
	  ++x;
	}
      ++y;
    }
  return (0);
}

static bool	check_right_case(const t_mino *mino, const t_opt *opts,
				 const t_info *info, const int **tray)
{
  int		y;
  int		x;

  y = info->sidey;
  if (info->sidex + mino->width == opts->map_col)
    return (1);
  while (y < info->sidey + mino->height)
    {
      x = info->sidex;
      while (x < info->sidex + mino->width)
	{
	  if (tray[y][x] > 0 && tray[y][x] < 10 && tray[y][x + 1] > 10)
	    return (1);
	  ++x;
	}
      ++y;
    }
  return (0);
}

bool	go_left(const t_mino *mino, t_info *info, int **tray)
{
  int	x;
  int	y;

  y = info->sidey;
  if (check_left_case(mino, info, (const int **)tray))
    return (1);
  else
    {
      while (y < info->sidey + mino->height)
	{
	  x = info->sidex - 1;
	  while (x < info->sidex + mino->width - 1)
	    {
	      if (tray[y][x + 1] > 0 && tray[y][x + 1] < 10)
		{
		  tray[y][x] = tray[y][x + 1];
		  tray[y][x + 1] = 0;
		}
	      ++x;
	    }
	  ++y;
	}
      --info->sidex;
    }
  return (0);
}

bool	go_right(const t_mino *mino, const t_opt *opts,
		 t_info *info, int **tray)
{
  int	x;
  int	y;

  y = info->sidey;
  if (check_right_case(mino, opts, info, (const int **)tray))
    return (1);
  else
    {
      while (y < info->sidey + mino->height)
	{
	  x = info->sidex + mino->width + 1;
	  while (x > info->sidex)
	    {
	      if (tray[y][x - 1] > 0 && tray[y][x - 1] < 10)
		{
		  tray[y][x] = tray[y][x - 1];
		  tray[y][x - 1] = 0;
		}
	      --x;
	    }
	  ++y;
	}
      ++info->sidex;
    }
  return (0);
}
