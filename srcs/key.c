/*
** key.c for key in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Wed Mar  9 00:59:19 2016 Loïs
** Last update Sun Mar 20 22:25:34 2016 Loïs
*/

#include <ncurses.h>
#include <signal.h>
#include "tetris.h"
#include "my.h"

bool	key_fast(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  if (my_strcmp(opts->key_fast, info->key))
    {
      if (!go_down(mino, opts, info, tray))
	{
	  g_time = 0;
	  kill(info->son, SIGKILL);
	}
      print_tray(mino, opts, info, (const int **)tray);
      return (1);
    }
  return (0);
}

bool	key_rotate(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  if (my_strcmp(opts->key_turn, info->key))
    {
      the_rotate(mino, opts, info, tray);
      print_tray(mino, opts, info, (const int **)tray);
      return (1);
    }
  return (0);
}

bool	key_drop(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  if (my_strcmp(opts->key_drop, info->key))
    {
      while (go_down(mino, opts, info, tray))
	(void)1;
      g_time = 0;
      kill(info->son, SIGKILL);
      print_tray(mino, opts, info, (const int **)tray);
      return (1);
    }
  return (0);
}

static void	process_pause(t_mino *mino, t_opt *opts, t_info *info, int mod)
{
  int		**tmp;

  if (mod == 0)
    {
      tmp = creat_tray(opts, info);
      print_tray(mino, opts, info, (const int **)tmp);
      mvprintw(8, 4, " ____   __   _  _  ____  ____ ");
      mvprintw(9, 4, "(  _ \\ / _\\ / )( \\/ ___)(  __)");
      mvprintw(10, 4, " ) __//    \\) \\/ (\\___ \\ ) _)");
      mvprintw(11, 4, "(__)  \\_/\\_/\\____/(____/(____)");
      mvprintw(12, 4, "                              ");
      mvprintw(13, 4, "                              ");
      free_tab(tmp, opts->map_row + info->max);
    }
  else
    {
      mvprintw(8, 4, "                              ");
      mvprintw(9, 4, "                              ");
      mvprintw(10, 4, "                              ");
      mvprintw(11, 4, "                              ");
    }
  refresh();
}

bool		key_pause(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  time_t	ref;
  time_t	act;

  if (my_strcmp(opts->key_pause, info->key))
    {
      info->key = NULL;
      kill(info->son, SIGUSR2);
      process_pause(mino, opts, info, 0);
      ref = time(&act);
      while (!my_strcmp(opts->key_pause, info->key))
	{
	  info->key = wait_for_key(0);
	  act = time(NULL);
	  aff_time(ref, act, 3, 14);
	  refresh();
	}
      info->ref = info->ref + (act - ref);
      process_pause(mino, opts, info, 1);
      print_tray(mino, opts, info, (const int **)tray);
      kill(info->son, SIGUSR1);
      return (1);
    }
  return (0);
}
