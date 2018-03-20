/*
** my_print_nbr_next.c for my_print_nbr_next in /home/antoin_g/rendu/Unix/PSU_2015_my_printf
**
** Made by Loïs Antoine
** Login   <antoin_g@Lois-Labtop>
**
** Started on  Tue Dec 22 15:57:29 2015 Loïs Antoine
** Last update Mon Jan 25 16:36:11 2016 Loïs Antoine
*/

#include "print.h"

int			my_print_short_unbr(const unsigned short nb, int n)
{
  unsigned short	a;

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

int		my_print_long_unbr(const unsigned long nb, int n)
{
  unsigned long	a;

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
