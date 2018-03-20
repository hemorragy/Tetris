/*
** key_tools.c for key_tools in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Mar 10 12:23:39 2016 Loïs
** Last update Sun Mar 20 23:10:00 2016 Loïs
*/

#include <ncurses.h>
#include <signal.h>
#include "tetris.h"
#include "my.h"

static bool	key_hold(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  if (my_strcmp(opts->key_hold, info->key))
    {
      if (info->o == 0)
	{
	  mino = switch_hold(mino, info);
	  g_rotate = 0;
	  clean_it(opts, info, tray);
	  place_piece_center(mino, opts, info, tray);
	  go_down(mino, opts, info, tray);
	  print_tray(mino, opts, info, (const int **)tray);
	  info->tmp = mino;
	  info->o = 1;
	}
      return (1);
    }
  return (0);
}

static bool	key_right(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  if (my_strcmp(opts->key_r, info->key))
    {
      go_right(mino, opts, info, tray);
      return (1);
    }
  return (0);
}

static bool	key_left(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  if (my_strcmp(opts->key_l, info->key))
    {
      go_left(mino, info, tray);
      return (1);
    }
  return (0);
}

static bool	key_stop(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  if (my_strcmp(opts->key_quit, info->key))
    {
      my_free_mino(mino->first);
      free_tab(tray, opts->map_row + info->max);
      kill(info->son, SIGKILL);
      endwin();
      mode_canonique(0, 0);
      exit(0);
    }
  return (0);
}

void	check_key(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  t_key	key[9];
  bool	check;
  int	i;

  key[0] = &key_drop;
  key[1] = &key_pause;
  key[2] = &key_rotate;
  key[3] = &key_stop;
  key[4] = &key_left;
  key[5] = &key_right;
  key[6] = &key_fast;
  key[7] = &key_hold;
  key[8] = NULL;
  i = 0;
  check = 0;
  while (key[i] != NULL && !check)
    {
      check = key[i](mino, opts, info, tray);
      ++i;
    }
}
