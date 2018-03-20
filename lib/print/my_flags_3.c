/*
** my_flags_3.c for my_flags_3 in /home/antoin_g/rendu/Unix/PSU_2015_my_printf
**
** Made by Loïs Antoine
** Login   <antoin_g@epitech.net>
**
** Started on  Thu Nov  5 22:53:53 2015 Loïs Antoine
** Last update Sat Mar 12 00:23:56 2016 Loïs
*/

#include <stdarg.h>
#include "print.h"

void	flag_b(va_list *ap, t_count *count, const char *str)
{
  if (str[count->i + 1] == 'b')
    {
      count->i = count->i + 2;
      count->n = my_printnbr_base(va_arg(*ap, unsigned int), "01", count->n);
    }
}

void	flag_mod(va_list *ap, t_count *count, const char *str)
{
  (void)*ap;
  if (str[count->i + 1] == '%')
    {
      count->i = count->i + 2;
      count->n = my_printchar('%', count->n);
    }
}

void	flag_p(va_list *ap, t_count *count, const char *str)
{
  long	ntest;

  if (str[count->i + 1] == 'p')
    {
      ntest = va_arg(*ap, long);
      if (ntest == 0)
	count->n = my_printstr("(nil)", count->n);
      else
	count->n = my_printf("0x%x", ntest) + count->n;
      count->i = count->i + 2;
    }
}

void	flag_hu(va_list *ap, t_count *count, const char *str)
{
  if (str[count->i + 1] == 'h' && str[count->i + 2] == 'u')
    {
      count->i = count->i + 3;
      count->n = my_print_unbr(va_arg(*ap, unsigned int), count->n);
    }
}

void	flag_lu(va_list *ap, t_count *count, const char *str)
{
  if ((str[count->i + 1] == 'l' && str[count->i + 2] == 'u'))
    {
      count->i = count->i + 3;
      count->n = my_print_unbr(va_arg(*ap, unsigned long), count->n);
    }
}
