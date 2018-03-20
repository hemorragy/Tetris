/*
** utils.c for TETRIS in /home/chouik_e/Rendu/xTODO/PSU_2015_tetris/srcs
**
** Made by Eddy Chouikha
** Login   <chouik_e@epitech.net>
**
** Started on  Sun Mar 20 10:46:35 2016 Eddy Chouikha
** Last update Sun Mar 20 23:03:01 2016 Loïs
*/

#include <sys/ioctl.h>
#include <ncurses.h>
#include <unistd.h>
#include <term.h>
#include "tetris.h"
#include "my.h"

int			mode_canonique(int i, int vmin)
{
  static struct termios	oldt;
  static struct termios	newt;

  if (i)
    {
      if (i == 3)
	ioctl(0, TCGETS, &oldt);
      ioctl(0, TCGETS, &newt);
      newt.c_lflag &= ~ECHO;
      newt.c_lflag &= ~ICANON;
      newt.c_cc[VMIN] = vmin;
      newt.c_cc[VTIME] = 0;
      ioctl(0, TCSETS, &newt);
    }
  else
    ioctl(0, TCSETS, &oldt);
  return (0);
}

char	*wait_for_key(int vmin)
{
  char	*buff;
  int	size;

  buff = xmalloc(11);
  mode_canonique(1, vmin);
  if ((size = read(0, buff, 10)) < 0)
    my_error(READ_FAILED);
  buff[size] = 0;
  return (buff);
}

static void	init_tmp(char **tmp, const t_opt *opts)
{
  tmp[0] = opts->key_l;
  tmp[1] = opts->key_r;
  tmp[2] = opts->key_turn;
  tmp[3] = opts->key_drop;
  tmp[4] = opts->key_hold;
  tmp[5] = opts->key_fast;
  tmp[6] = opts->key_pause;
  tmp[7] = opts->key_quit;
  tmp[8] = NULL;
}

void	is_double(const t_opt *opts)
{
  char	**tmp;
  int	i;
  int	x;

  i = 0;
  tmp = xmalloc(9 * sizeof(char *));
  init_tmp(tmp, opts);
  while (i < 7)
    {
      x = i + 1;
      while (x < 8)
	{
	  if (my_strcmp(tmp[i], tmp[x]))
	    my_error(SAME_KEYS_SET);
	  ++x;
	}
      ++i;
    }
  free(tmp);
}

void	init_opts(t_opt *opts)
{
  int	ret;

  if (setupterm(NULL, 1, &ret) == ERR)
    my_error(INVALID_TERM);
  if ((*(opts->key_l = tigetstr("kcub1")) <= 0) ||
      (*(opts->key_r = tigetstr("kcuf1")) <= 0) ||
      (*(opts->key_turn = tigetstr("kcuu1")) <= 0) ||
      (*(opts->key_drop = tigetstr("kcud1")) <= 0))
    my_error(NO_ARROWS_FOUND);
  opts->key_fast = my_strdup("f");
  opts->key_hold = my_strdup("h");
  opts->key_quit = my_strdup("q");
  opts->key_pause = my_strdup(" ");
  opts->level = 1;
  opts->map_row = 20;
  opts->map_col = 10;
  opts->hide_next = 0;
  opts->debug = 0;
  is_double(opts);
}
