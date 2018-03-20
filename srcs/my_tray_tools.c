/*
** my_tray_tools.c for my_tray_tools in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Sat Mar  5 04:53:46 2016 Loïs
** Last update Sun Mar 20 22:42:24 2016 Loïs
*/

#include <ncurses.h>
#include "tetris.h"

void	set_clr_pair(void)
{
  init_pair(2, 7, -1);
  init_pair(3, 1, 1);
  init_pair(4, 2, 2);
  init_pair(5, 3, 3);
  init_pair(6, 4, 4);
  init_pair(7, 5, 5);
  init_pair(8, 6, 6);
  init_pair(9, 7, 7);
}

static void	aff_next_utils(const t_opt *opts, const t_info *info,
			       const t_next *next)
{
  int		idx;
  int		xplace;

  idx = 0;
  xplace = opts->map_col * 2 + 42 + next->sidex;
  while (idx < next->w * 2 &&
	 (next->i > next->sidey - 1 && next->i < next->h + next->sidey))
    {
      attron(COLOR_PAIR(info->next->color + 2));
      if (info->next->piece[0][next->i - next->sidey][idx / 2] == 1)
	mvprintw(next->i + 3, idx + xplace, "  ");
      attroff(COLOR_PAIR(info->next->color + 2));
      idx = idx + 2;
    }
}

static void	aff_next_tool(const t_mino *mino, const t_opt *opts,
			      const t_info *info, t_next *next)
{
  next->i = 1;
  if (mino == info->next && g_rotate % 2 == 1)
    {
      next->h = mino->width;
      next->w = mino->height;
    }
  else
    {
      next->h = info->next->height;
      next->w = info->next->width;
    }
  next->sidey = ((next->maxi - next->h) ? (next->maxi - next->h) / 2 : 0) + 2;
  next->sidex = ((next->maxi - next->w > 0) ?
		 (next->maxi - next->w) / 2 : 0) * 2;
  while (next->i < next->maxi + 4)
    {
      mvprintw(++next->i, opts->map_col * 2 + 40, "|");
      mvprintw(next->i, opts->map_col * 2 + 43 + next->maxi * 2, "|");
      aff_next_utils(opts, info, next);
    }
}

void		aff_next(const t_mino *mino, const t_opt *opts,
			 const t_info *info)
{
  int		i;
  int		idx;
  t_next	next;

  next.maxi = (info->max > 4) ? info->max : 5;
  i = opts->map_col * 2 + 40;
  mvprintw(1, opts->map_col * 2 + 40, "/");
  mvprintw(5 + next.maxi, opts->map_col * 2 + 40, "\\");
  mvprintw(2, opts->map_col * 2 + 41, "Next:");
  while (i < (opts->map_col + next.maxi) * 2 + 42)
    {
      ++i;
      mvprintw(1, i, "--");
      mvprintw(3, i, "--");
      mvprintw(5 + next.maxi, i, "--");
      idx = 3;
      while (idx < 4 + next.maxi)
        mvprintw(++idx, i, " ");
    }
  mvprintw(1, (opts->map_col + next.maxi) * 2 + 43, "\\");
  mvprintw(5 + next.maxi, (opts->map_col + next.maxi) * 2 + 43, "/");
  i = 1;
  aff_next_tool(mino, opts, info, &next);
}
