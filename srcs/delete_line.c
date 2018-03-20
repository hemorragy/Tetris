/*
** delete_line.c for delete_line in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Fri Mar 18 11:45:10 2016 Loïs
** Last update Sun Mar 20 22:06:43 2016 Loïs
*/

#include <ncurses.h>
#include <unistd.h>
#include "tetris.h"
#include "my.h"

static void	print_explosion(int y, int x1, int x2, int color)
{
  attron(COLOR_PAIR(color));
  mvprintw(y, x1, "  ");
  mvprintw(y, x2, "  ");
  attroff(COLOR_PAIR(color));
  refresh();
  usleep(75000);
}

static void	explosion_effect(const t_opt *opts, const t_info *info, int i)
{
  static int	advance = 0;
  int		middle1;
  int		middle2;

  if (i >= info->max)
    {
      middle1 = (opts->map_col % 2) ? opts->map_col : opts->map_col - 1;
      middle2 = (opts->map_col % 2) ? opts->map_col : opts->map_col + 1;
      while (middle1 >= 0)
	{
	  print_explosion(i - info->max + 1 - advance, middle1 + 35,
			  middle2 + 35, 9);
	  print_explosion(i - info->max + 1 - advance, middle1 + 35,
			  middle2 + 35, 2);
	  attron(COLOR_PAIR(9));
	  middle2 = middle2 + 2;
	  middle1 = middle1 - 2;
	}
    }
  advance = (i > 0) ? advance + 1 : 0;
}

static void	set_score(t_info *info, int *lines, int score)
{
  if (info->score < 2000000000)
    info->score = info->score + info->level * score;
  info->score = (info->score > 2000000000 || info->score < 0) ?
    2000000000 : info->score;
  ++*lines;
  ++info->advance;
  if (*lines == 10)
    {
      ++info->level;
      *lines = 0;
    }
}

static void	shift_line(const t_opt *opts, t_info *info, int **tray, int i)
{
  static int	lines = 0;
  static int	score = 40;

  explosion_effect(opts, info, i);
  if (i == -1)
    {
      score = 40;
      return ;
    }
  while (i - 1 >= 0)
    {
      tray[i] = my_strcpint(tray[i], tray[i - 1], opts->map_col);
      --i;
    }
  set_score(info, &lines, score);
  score = (score == 200) ? 900 : score;
  score = (score == 60) ? 200 : score;
  score = (score == 40) ? 60 : score;
}

void	supress_line(int **tray, t_opt *opts, t_info *info)
{
  int	i;
  int	idx;
  bool	check;

  i = opts->map_row + info->max - 1;
  while (i >= 0)
    {
      idx = 0;
      check = 0;
      while (idx < opts->map_col && check == 0)
	{
	  if (tray[i][idx] == 0)
	    check = 1;
	  ++idx;
	}
      if (check == 0)
	shift_line(opts, info, tray, i);
      else
        --i;
    }
  shift_line(NULL, info, NULL, -1);
}
