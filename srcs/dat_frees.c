/*
** dat_frees.c for dat_frees in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Feb 25 23:43:45 2016 Loïs
** Last update Sun Mar 20 21:46:15 2016 Loïs
*/

#include <stdlib.h>
#include "tetris.h"

void	free_tab(int **tab, int y)
{
  int	i;

  i = 0;
  while (i < y)
    {
      free(tab[i]);
      ++i;
    }
  free(tab);
}

void	free_minos(t_mino *mino, int n)
{
  int	i;
  int	id;

  if (mino->piece != NULL)
    {
      i = 0;
      while (i < n)
	{
	  id = 0;
	  while (id < mino->height)
	    {
	      free(mino->piece[i][id]);
	      ++id;
	    }
	  free(mino->piece[i]);
	  ++i;
	  id = mino->height;
	  mino->height = mino->width;
	  mino->width = id;
	}
      free(mino->piece);
    }
}

void	my_free_mino(t_mino *mino)
{
  while (mino != mino->first)
    {
      free(mino->name);
      free_minos(mino, 4);
      mino = mino->next;
      free(mino->prev);
    }
  free(mino->name);
  free_minos(mino, 4);
  free(mino);
}
