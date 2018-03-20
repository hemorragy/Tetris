/*
** display_mino.c for display_mino in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Wed Feb 24 19:43:11 2016 Loïs
** Last update Sun Mar 20 22:11:27 2016 Loïs
*/

#include "tetris.h"
#include "print.h"
#include "my.h"

void	check_validate_form(t_mino *mino)
{
  int	i;
  bool	check;

  i = 0;
  check = 0;
  while (i < mino->height)
    {
      if (mino->piece != NULL)
	if (mino->piece[0][i][mino->width - 1] != 0)
	  check = 1;
      ++i;
    }
  if (check == 0)
    mino->piece = NULL;
}

static void	bubble_sort(char **sort)
{
  char		*tmp;
  int		swap;
  int		i;

  swap = 0;
  i = 0;
  while (sort[i + 1] != NULL || swap != 0)
    {
      if (my_strsort(sort[i], sort[i + 1]) > 0)
	{
	  tmp = sort[i];
	  sort[i] = sort[i + 1];
	  sort[i + 1] = tmp;
	  ++swap;
	}
      ++i;
      if (sort[i + 1] == NULL && swap != 0)
	{
	  swap = 0;
	  i = 0;
	}
    }
}

static void	fill_sort(const t_mino *mino, char **sort, int idx)
{
  int		i;

  i = 0;
  while (i < idx)
    {
      sort[i] = mino->name;
      mino = mino->next;
      ++i;
    }
  sort[i] = NULL;
}

static void	display_info(const t_mino *mino, int idx)
{
  int		i;

  my_printf("Tetriminos : Name %s : ", mino->name);
  if (mino->piece == NULL)
    my_printf("Error\n");
  else
    {
      my_printf("Size %d*%d : Color %d :\n", mino->width, mino->height,
		mino->color);
      while (idx < mino->height)
	{
	  i = 0;
	  while (i < mino->width)
	    {
	      if (mino->piece[0][idx][i] == 0 &&
		  check_for_next_thing(mino->piece[0][idx], i, mino->width))
		my_printf(" ");
	      else if (mino->piece[0][idx][i] == 1)
		my_printf("*");
	      ++i;
	    }
	  ++idx;
	  my_printf("\n");
	}
    }
}

void	display_mino(const t_mino *mino)
{
  char	**sort;
  int	i;

  i = 1;
  mino = mino->next;
  while (mino != mino->first)
    {
      ++i;
      mino = mino->next;
    }
  my_printf("Tetriminos : %d\n", i);
  sort = xmalloc(sizeof(char *) * (i + 1));
  fill_sort(mino->first, sort, i);
  bubble_sort(sort);
  i = 0;
  while (sort[i] != NULL)
    {
      while (!my_strcmp(sort[i], mino->name))
	mino = mino->next;
      display_info(mino, 0);
      mino = mino->first;
      ++i;
    }
  free(sort);
}
