/*
** aff_tetris.c for aff_tetris in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Feb 25 21:28:43 2016 Loïs
** Last update Sun Mar 20 22:02:00 2016 Loïs
*/

#include <ncurses.h>
#include "tetris.h"
#include "print.h"
#include "my.h"

bool	extra_term_size(const t_opt *opts, t_info *info)
{
  int	maxi;
  int	maxy;

  maxi = ((info->max > 4) ? info->max : 5) * 2;
  maxy = (opts->map_row + 2 > 16) ? opts->map_row + 2 : 16;
  maxy = (maxy < 14 + info->max * 2) ? 14 + info->max * 2 : maxy;
  getmaxyx(stdscr, info->line, info->col);
  if (info->line < maxy || info->col < opts->map_col + 44 + maxi * 2)
    return (1);
  return (0);
}

static void	get_size_max(const t_mino *mino, t_info *info)
{
  if (mino->piece != NULL)
    info->max = (mino->height > mino->width) ? mino->height : mino->width;
  mino = mino->next;
  while (mino != mino->first)
    {
      if (mino->piece != NULL &&
	  (mino->height > info->max || mino->width > info->max))
	info->max = mino->height;
      mino = mino->next;
    }
}

static t_mino	*after_fall(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  info->o = 0;
  supress_line(tray, opts, info);
  print_tray(mino, opts, info, (const int **)tray);
  mino = info->next;
  info->tmp = mino;
  info->next = take_new_piece(mino);
  return (mino);
}

static void	term_tools(t_info *info, t_opt *opts, t_mino *mino, int **tray)
{
  if (start_color() == ERR || use_default_colors() == ERR)
    my_error("Error : terminal don't support color\n");
  set_clr_pair();
  if (extra_term_size(opts, info))
    {
      endwin();
      my_error("Error : Terminal too small\n");
    }
  info->ref = time(&info->time);
  mino = take_new_piece(mino);
  info->next = take_new_piece(mino);
  info->tmp = mino;
  while (place_piece_center(mino, opts, info, tray))
    {
      while (go_down(mino, opts, info, tray))
	{
	  action_curse(mino, opts, info, tray);
	  mino = info->tmp;
	}
      mino = after_fall(mino, opts, info, tray);
    }
}

void		create_curse(t_mino *mino, t_opt *opts)
{
  t_info	info;
  int		**tray;

  info.score = 0;
  info.o = 0;
  info.hold = NULL;
  info.advance = 0;
  info.level = opts->level;
  g_rotate = 0;
  get_size_max(mino->first, &info);
  tray = creat_tray(opts, &info);
  initscr();
  raw();
  keypad(stdscr, TRUE);
  curs_set(0);
  term_tools(&info, opts, mino, tray);
  endwin();
  my_printf("\n=============\n  You loose\n=============\nScore : %d\nLines : "
	    "%d\nLevel : %d\n\n", info.score, info.advance, info.level);
  free_tab(tray, opts->map_row + info.max);
}
