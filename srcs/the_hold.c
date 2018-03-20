/*
** my_tray_utils.c for my_tray_utils in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Fri Mar 18 18:54:13 2016 Loïs
** Last update Sun Mar 20 22:56:21 2016 Loïs
*/

#include <ncurses.h>
#include "tetris.h"

t_mino		*switch_hold(t_mino *mino, t_info *info)
{
  t_mino	*tmp;
  int		temp;

  if (g_rotate % 2 == 1)
    {
      temp = mino->width;
      mino->width = mino->height;
      mino->height = temp;
    }
  if (info->hold == NULL)
    {
      info->hold = mino;
      mino = info->next;
      info->next = take_new_piece(mino);
    }
  else
    {
      tmp = info->hold;
      info->hold = mino;
      mino = tmp;
    }
  return (mino);
}

void	clean_it(const t_opt *opts, const t_info *info, int **tray)
{
  int	i;
  int	idx;

  i = 0;
  while (i < opts->map_row + info->max)
    {
      idx = 0;
      while (idx < opts->map_col)
	{
	  if (tray[i][idx] > 0 && tray[i][idx] < 10)
	    tray[i][idx] = 0;
	  ++idx;
	}
      ++i;
    }
}

static void	aff_hold_utils(const t_opt *opts, const t_info *info,
			      const t_hold *hold)
{
  int		idx;
  int		xplace;

  idx = 0;
  xplace = opts->map_col * 2 + 42 + hold->sidex;
  while (idx < hold->w * 2 &&
	 (hold->i > hold->sidey - 1 && hold->i < hold->h + hold->sidey))
    {
      attron(COLOR_PAIR(info->hold->color + 2));
      if (info->hold->piece[0][hold->i - hold->sidey][idx / 2] == 1)
	mvprintw(hold->i + 3, idx + xplace, "  ");
      attroff(COLOR_PAIR(info->hold->color + 2));
      idx = idx + 2;
    }
}

static void	aff_hold_tool(const t_mino *mino, const t_opt *opts,
			     const t_info *info, t_hold *hold)
{
  hold->i = 7 + hold->maxi;
  if (info->hold != NULL)
    {
      if (mino == info->hold && g_rotate % 2 == 1)
	{
	  hold->h = mino->width;
	  hold->w = mino->height;
	}
      else
	{
	  hold->h = info->hold->height;
	  hold->w = info->hold->width;
	}
      hold->sidey = ((hold->maxi - hold->h) ? (hold->maxi - hold->h) / 2 : 0)
	+ 8 + hold->maxi;
      hold->sidex = ((hold->maxi - hold->w > 0) ?
		    (hold->maxi - hold->w) / 2 : 0) * 2;
    }
  while (hold->i < hold->maxi * 2 + 10)
    {
      mvprintw(++hold->i, opts->map_col * 2 + 40, "|");
      mvprintw(hold->i, opts->map_col * 2 + 43 + hold->maxi * 2, "|");
      if (info->hold != NULL)
	aff_hold_utils(opts, info, hold);
    }
}

void		aff_hold(const t_mino *mino, const t_opt *opts,
			const t_info *info)
{
  int		i;
  int		idx;
  t_hold	hold;

  hold.maxi = (info->max > 4) ? info->max : 5;
  i = opts->map_col * 2 + 40;
  mvprintw(7 + hold.maxi, opts->map_col * 2 + 40, "/");
  mvprintw(11 + hold.maxi * 2, opts->map_col * 2 + 40, "\\");
  mvprintw(8 + hold.maxi, opts->map_col * 2 + 41, "Hold:");
  while (i < (opts->map_col + hold.maxi) * 2 + 42)
    {
      ++i;
      mvprintw(7 + hold.maxi, i, "--");
      mvprintw(9 + hold.maxi, i, "--");
      mvprintw(11 + hold.maxi * 2, i, "--");
      idx = 9 + hold.maxi;
      while (idx < 10 + hold.maxi * 2)
	mvprintw(++idx, i, " ");
    }
  mvprintw(7 + hold.maxi, (opts->map_col + hold.maxi) * 2 + 43, "\\");
  mvprintw(11 + hold.maxi * 2, (opts->map_col + hold.maxi) * 2 + 43, "/");
  aff_hold_tool(mino, opts, info, &hold);
}
