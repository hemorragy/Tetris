/*
** options.c for options in /home/chouik_e/Rendu/TODO/PSU_2015_tetris
**
** Made by Eddy Chouikha
** Login   <chouik_e@chouik-e-pc>
**
** Started on  Mon Feb 22 22:54:48 2016 Eddy Chouikha
** Last update Sun Mar 20 22:03:43 2016 Loïs
*/

#include <term.h>
#include "tetris.h"
#include "print.h"

static int	my_outc(const int c)
{
  if (c == 27)
    my_printf("^E");
  else if (c == ' ')
    my_printf("(space)");
  else
    my_printf("%c", c);
  return (0);
}

static void	print_key(const char *key_name, char *key_value)
{
  my_printf("%s : ", key_name);
  tputs(key_value, 1, my_outc);
  my_printf("\n");
}

void	debug_mode(const t_opt *opts,const t_mino *mino)
{
  my_printf("*** DEBUG MODE ***\n");
  print_key("Key Left", opts->key_l);
  print_key("Key Right", opts->key_r);
  print_key("Key Turn", opts->key_turn);
  print_key("Key Drop", opts->key_drop);
  print_key("Key Quit", opts->key_quit);
  print_key("Key Pause", opts->key_pause);
  if (opts->hide_next)
    my_printf("Next : No\n");
  else
    my_printf("Next : Yes\n");
  my_printf("Level : %d\n", opts->level);
  my_printf("Size : %d*%d\n", opts->map_row, opts->map_col);
  display_mino(mino);
  my_printf("Press a key to start Tetris\n");
  wait_for_key(1);
}
