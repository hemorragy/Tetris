/*
** my_putchar.c for my_putchar in /home/antoin_g/rendu/lib/my
**
** Made by Loïs Antoine
** Login   <antoin_g@epitech.net>
**
** Started on  Thu Oct 15 15:34:24 2015 Loïs Antoine
** Last update Mon Mar 14 17:31:34 2016 Loïs
*/

#include <unistd.h>
#include "print.h"

int	my_printlen(const char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    ++a;
  return (a);
}

int	my_printchar(const char a, int n)
{
  return (n + write(1, &a, 1));
}

int	my_printstr(const char *str, int n)
{
  return (write(1, str, my_printlen(str)) + n);
}

int	my_showfstr(const char *str, int n)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      while (str[i] < 32 || str[i] >= 127)
	{
	  n = my_printchar('\\', n);
	  if (str[i] < 8)
	    n = my_printchar('0', n);
	  if (str[i] < 64)
	    n = my_printchar('0', n);
	  n = my_printnbr_base(str[i], "01234567", n);
	  ++i;
	}
      n = my_printchar(str[i], n);
      ++i;
    }
  return (n);
}

int	my_pointnbr_base(long nbr, char *base, int n)
{
  long	div;
  long	size;

  div = 1;
  size = my_printlen(base);
  if (nbr < 0)
    {
      n = my_printchar('-', n);
      nbr = nbr * -1;
    }
  while ((nbr / div) >= size)
    div = div * size;
  while (div > 0)
    {
      n = my_printchar(base[nbr / div % size], n);
      div = div / size;
    }
  return (n);
}
