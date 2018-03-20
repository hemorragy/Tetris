/*
** game_progress.c for game_progress in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Mar  3 01:31:47 2016 Loïs
** Last update Sun Mar 20 22:13:31 2016 Loïs
*/

#include <ncurses.h>
#include <signal.h>
#include <unistd.h>
#include "tetris.h"
#include "my.h"

static void	handler(int sig)
{
  if (sig == SIGUSR1)
    g_time = 0;
  if (sig == SIGUSR2)
    g_pause = 1;
}

static void	the_dad(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  g_time = 1;
  while (g_time)
    {
      info->key = NULL;
      if (signal(SIGUSR1, handler) == SIG_ERR)
        my_error("Error : Signal error\n");
      if (extra_term_size(opts, info))
	{
	  endwin();
	  kill(info->son, SIGINT);
	  my_error("Error : Terminal too small\n");
	}
      print_tray(mino, opts, info, (const int **)tray);
      info->key = wait_for_key(0);
      if (info->key != NULL)
	check_key(mino, opts, info, tray);
      mino = info->tmp;
    }
}

static void	the_son(t_info *info, pid_t dad)
{
  float		dodo;
  int		i;

  dodo = 1.0;
  i = 0;
  while (i < info->level)
    {
      dodo = dodo + (dodo / 5);
      ++i;
    }
  i = 0;
  g_pause = 0;
  while (i < 100)
    {
      if (signal(SIGUSR2, handler) == SIG_ERR)
	my_error("Error : Signal error\n");
      usleep(10000 / dodo);
      if (g_pause == 1)
	pause();
      g_pause = 0;
      ++i;
    }
  kill(dad, SIGUSR1);
  exit(0);
}

void	action_curse(t_mino *mino, t_opt *opts, t_info *info, int **tray)
{
  pid_t	dad;
  pid_t	i;

  dad = getpid();
  print_tray(mino, opts, info, (const int **)tray);
  if ((i = fork()) == -1)
    my_error("Error : process duplication failed\n");
  if (i == 0)
    the_son(info, dad);
  else
    {
      info->son = i;
      the_dad(mino, opts, info, tray);
    }
}
