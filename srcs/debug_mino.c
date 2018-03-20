/*
** debug_mino.c for debug_mino in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Mar 17 17:38:39 2016 Loïs
** Last update Sun Mar 20 23:18:57 2016 Loïs
*/

#include "tetris.h"
#include "my.h"

void	if_valid_mino(const t_mino *mino)
{
  bool	i;

  i = 0;
  if (mino->piece != NULL)
    i = 1;
  mino = mino->next;
  while (mino != mino->first && i == 0)
    {
      if (mino->piece != NULL)
	i = 1;
      mino = mino->next;
    }
  if (i == 0)
    my_error("Error : no valid mino\n");
}

bool	check_for_next_thing(const bool *piece, int idx, int width)
{
  while (idx < width)
    {
      if (piece[idx] == 1)
	return (1);
      ++idx;
    }
  return (0);
}

int	end_space(const char *str)
{
  int	i;
  int	count;

  i = my_strlen(str) - 1;
  count = 0;
  while (str[i] == ' ' && i > 0)
    {
      --i;
      ++count;
    }
  return (count);
}
