/*
** my_tray.c for my_tray in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Mar  3 01:28:04 2016 Loïs
** Last update Sun Mar 20 22:37:51 2016 Loïs
*/

#include <ncurses.h>
#include "tetris.h"
#include "my.h"

void	aff_time(time_t ref, time_t time, int x, int y)
{
  int	aff_time;

  aff_time = (time - ref) / 3600;
  if (aff_time < 10)
    mvprintw(y, x, "| Timer :       0%d:", aff_time);
  else
    mvprintw(y, x, "| Timer :       %d:", aff_time);
  aff_time = (time - ref) % 3600 / 60;
  if (aff_time < 10)
    mvprintw(y, x + 19, "0%d:", aff_time);
  else
    mvprintw(y, x + 19, "%d:", aff_time);
  aff_time = (time - ref) % 3600 % 60;
  if (aff_time < 10)
    mvprintw(y, x + 22, "0%d", aff_time);
  else
    mvprintw(y, x + 22, "%d", aff_time);
}

static void	print_tab(const t_opt *opts, const t_info *info,
			  const int **tray, int i)
{
  int		idx;
  int		color;
  int		yplace;

  idx = 0;
  yplace = i + 1 - info->max;
  while (idx < opts->map_col * 2)
    {
      color = tray[i][idx / 2] % 10;
      attron(COLOR_PAIR(color + 2));
      mvprintw(yplace, idx + 36, "  ");
      attroff(COLOR_PAIR(color + 2));
      idx = idx + 2;
    }
}

static void	aff_tray(const t_opt *opts, const t_info *info,
			 const int **tray)
{
  int		end_loop;
  int		xplace;
  int		yplace;
  int		i;

  i = 35;
  yplace = opts->map_row + 1;
  end_loop = opts->map_col * 2 + 37;
  while (i < end_loop)
    {
      mvprintw(0, i, "-");
      mvprintw(yplace, i, "-");
      ++i;
    }
  i = info->max;
  xplace = opts->map_col * 2 + 36;
  yplace = info->max - 1;
  while (i - info->max < opts->map_row)
    {
      mvprintw(i - yplace, 35, "|");
      mvprintw(i - yplace, xplace, "|");
      print_tab(opts, info, tray, i);
      ++i;
    }
}

void	print_tray(const t_mino *mino, const t_opt *opts,
		   t_info *info, const int **tray)
{
  mvprintw(0, 0, " ____  ____  ____  ____  __  ____");
  mvprintw(1, 0, "(_  _)(  __)(_  _)(  _ \\(  )/ ___)");
  mvprintw(2, 0, "  )(   ) _)   )(   )   / )( \\___ \\");
  mvprintw(3, 0, " (__) (____) (__) (__\\_)(__)(____/");
  mvprintw(6, 3, "/-------------------------\\");
  mvprintw(7, 3, "|                         |");
  mvprintw(8, 3, "| Score :       %d", info->score);
  mvprintw(8, 29, "|\n   |                         |");
  mvprintw(10, 3, "| Level :       %d", info->level);
  mvprintw(10, 29, "|");
  mvprintw(11, 3, "| Lines :       %d", info->advance);
  mvprintw(11, 29, "|\n   |                         |");
  mvprintw(13, 29, "|\n   |                         |");
  mvprintw(15, 3, "\\-------------------------/");
  info->time = time(NULL);
  aff_time(info->ref, info->time, 3, 13);
  aff_tray(opts, info, tray);
  if (opts->hide_next == 0)
    aff_next(mino, opts, info);
  aff_hold(mino, opts, info);
  if (refresh() == ERR)
    {
      endwin();
      my_error("Error : refreshing terminal failed\n");
    }
}

int	**creat_tray(const t_opt *opts, const t_info *info)
{
  int	**tray;
  int	idx;
  int	i;

  tray = xmalloc(sizeof(int *) * (opts->map_row + info->max));
  i = 0;
  while (i < opts->map_row + info->max)
    {
      tray[i] = xmalloc(sizeof(int) * opts->map_col);
      idx = 0;
      while (idx < opts->map_col)
        {
          tray[i][idx] = 0;
          ++idx;
        }
      ++i;
    }
  return (tray);
}
