/*
** main.c for main in /home/chouik_e/Rendu/TODO/PSU_2015_tetris
**
** Made by Eddy Chouikha
** Login   <chouik_e@chouik-e-pc>
**
** Started on  Mon Feb 22 14:27:08 2016 Eddy Chouikha
** Last update Sun Mar 20 22:26:39 2016 Loïs
*/

#include <stdlib.h>
#include "tetris.h"

static void	rotate_all(t_mino *mino)
{
  if (mino->piece != NULL)
    rotate_pieces(mino, 1);
  mino = mino->next;
  while (mino != mino->first)
    {
      if (mino->piece != NULL)
	rotate_pieces(mino, 1);
      mino = mino->next;
    }
}

int		main(int ac, char **av)
{
  t_mino	*mino;
  t_opt		opts;

  mode_canonique(3, 0);
  srand(time(NULL));
  init_opts(&opts);
  if (ac > 1)
    check_args(av, &opts);
  mino = get_tetrimino(&opts);
  rotate_all(mino->first);
  if (opts.debug)
    debug_mode(&opts, mino);
  if_valid_mino(mino->first);
  create_curse(mino, &opts);
  my_free_mino(mino->first->next);
  mode_canonique(0, 1);
  return (0);
}
