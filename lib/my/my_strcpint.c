/*
** my_strcpint.c for my_strcpint in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Tue Mar 15 15:40:50 2016 Loïs
** Last update Tue Mar 15 15:41:33 2016 Loïs
*/

int	*my_strcpint(int * const dest, int const * const src, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      dest[i] = src[i];
      ++i;
    }
  return (dest);
}
