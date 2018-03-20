/*
** my_put_nbr.c for my_put_nbr in /home/antoin_g/rendu/Piscine_C_J03
**
** Made by Loïs Antoine
** Login   <antoin_g@epitech.net>
**
** Started on  Fri Oct  2 11:28:04 2015 Loïs Antoine
** Last update Mon Jan 25 16:35:17 2016 Loïs Antoine
*/

#include "print.h"

int		my_printnbr_base(const unsigned int nb, const char *base, int n)
{
  unsigned int	div;
  unsigned int	size;

  div = 1;
  size = my_printlen(base);
  while ((nb / div) >= size)
    div = div * size;
  while (div > 0)
    {
      n = my_printchar(base[nb / div % size], n);
      div = div / size;
    }
  return (n);
}

int		my_print_unbr(const unsigned int nb, int n)
{
  unsigned int	a;

  a = 1;
  while (a <= nb / 10)
    a = a * 10;
  while (a > 0)
    {
      n = my_printchar(nb / a % 10 + 48, n);
      a = a / 10;
    }
  return (n);
}

int	my_print_long_nbr(long nb, int n)
{
  long	a;

  if (nb < 0)
    {
      n = my_printchar('-', n);
      nb = -nb;
    }
  a = 1;
  while (a <= nb / 10)
    a = a * 10;
  while (a > 0)
    {
      n = my_printchar(nb / a % 10 + 48, n);
      a = a / 10;
    }
  return (n);
}

int	my_print_short_nbr(short nb, int n)
{
  short	a;

  if (nb < 0)
    {
      n = my_printchar('-', n);
      nb = -nb;
    }
  a = 1;
  while (a <= nb / 10)
    a = a * 10;
  while (a > 0)
    {
      n = my_printchar(nb / a % 10 + 48, n);
      a = a / 10;
    }
  return (n);
}

int	my_print_nbr(int nb, int n)
{
  long	a;

  if (nb == -2147483648)
    n = my_printstr("-2147483648", n);
  else
    {
      if (nb < 0)
	{
	  n = my_printchar('-', n);
	  nb = -nb;
	}
      a = 1;
      while (a <= nb / 10)
	a = a * 10;
      while (a > 0)
	{
	  n = my_printchar(nb / a % 10 + 48, n);
	  a = a / 10;
	}
    }
  return (n);
}
