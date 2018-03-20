/*
** options.c for options in /home/chouik_e/Rendu/TODO/PSU_2015_tetris
**
** Made by Eddy Chouikha
** Login   <chouik_e@chouik-e-pc>
**
** Started on  Mon Feb 22 22:54:48 2016 Eddy Chouikha
** Last update Sun Mar 20 22:44:19 2016 Loïs
*/

#include "tetris.h"
#include "print.h"
#include "my.h"

static void	init_ptr_tab(t_ptr *ptr)
{
  ptr[0] = &my_set_level;
  ptr[1] = &my_set_key_l;
  ptr[2] = &my_set_key_r;
  ptr[3] = &my_set_key_turn;
  ptr[4] = &my_set_key_drop;
  ptr[3] = &my_set_key_hold;
  ptr[4] = &my_set_key_fast;
  ptr[5] = &my_set_key_quit;
  ptr[6] = &my_set_key_pause;
  ptr[7] = &my_set_map_size;
  ptr[8] = &my_set_hide_next;
  ptr[9] = &my_set_debug;
}

static void	print_help(const char *bin_name)
{
  my_printf("Usage: %s [options]\nOptions:\n", bin_name);
  my_printf("  --help\t\tDisplay this help\n");
  my_printf("  -l --level={num}\tStart Tetris at level num\n");
  my_printf("  -kl --key-left={K}\tMove tetrimino on LEFT with key K\n");
  my_printf("  -kr --key-right={K}\tMove tetrimino on RIGHT with key K\n");
  my_printf("  -kt --key-turn={K}\tTurn tetrimino with key K\n");
  my_printf("  -kd --key-drop={K}\tSet default DROP on key K\n");
  my_printf("  -kq --key-quit={K}\tQuit program when press key K\n");
  my_printf("  -kp --key-pause={K}\tPause and restart game when press key K\n");
  my_printf("  --map-size={row,col}\tSet game size at row, col\n");
  my_printf("  -w --without-next\tHide next tetrimino\n");
  my_printf("  -d --debug\t\tDebug mode\n");
  mode_canonique(0, 0);
  exit(EXIT_SUCCESS);
}

static void	loop_func_ptr(int *i, char **av, t_opt *opts, t_ptr *ptr)
{
  bool		flag;
  int		x;

  flag = 0;
  x = 0;
  while (x < 10)
    {
      if (ptr[x](opts, i, av))
	{
	  flag = 1;
	  x = 9;
	}
      ++x;
    }
  if (flag == 0)
    my_error(INVALID_OPT);
}

void	check_args(char **av, t_opt *opts)
{
  int	i;
  t_ptr	ptr[10];

  i = 1;
  init_ptr_tab(ptr);
  while (av[i] != NULL)
    {
      if (my_strcmp(av[i], "--help"))
	print_help(av[0]);
      else
	loop_func_ptr(&i, av, opts, ptr);
      i++;
    }
  is_double(opts);
}
