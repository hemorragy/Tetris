/*
** my_flags_2.c for my_flags_2 in /home/antoin_g/rendu/Unix/PSU_2015_my_printf
** 
** Made by Loïs Antoine
** Login   <antoin_g@epitech.net>
** 
** Started on  Thu Nov  5 22:51:34 2015 Loïs Antoine
** Last update Mon Jan 25 16:44:15 2016 Loïs Antoine
*/

#include <stdarg.h>
#include <stdlib.h>
#include "print.h"

void	flag_s(va_list *ap, t_count *count, const char *str)
{
  char	*ntest;

  if (str[count->i + 1] == 's')
    {
      ntest = va_arg(*ap, char *);
      if (ntest == NULL)
	count->n = my_printstr("(null)", count->n);
      else
	count->n = my_printstr(ntest, count->n);
      count->i = count->i + 2;
    }
}

void	flag_S(va_list *ap, t_count *count, const char *str)
{
  char	*ntest;

  if (str[count->i + 1] == 'S')
    {
      ntest = va_arg(*ap, char *);
      if (ntest == NULL)
	count->n = my_printstr("(null)", count->n);
      else
	count->n = my_showfstr(ntest, count->n);
      count->i = count->i + 2;
    }
}

void	flag_c(va_list *ap, t_count *count, const char *str)
{
  if (str[count->i + 1] == 'c')
    {
      count->i = count->i + 2;
      count->n = my_printchar(va_arg(*ap, int), count->n);
    }
}

void	flag_ld(va_list *ap, t_count *count, const char *str)
{
  if (str[count->i + 1] == 'l' && str[count->i + 2] == 'd')
    {
      count->n = my_print_long_nbr(va_arg(*ap, long), count->n);
      count->i = count->i + 3;
    }
}

void	flag_hd(va_list *ap, t_count *count, const char *str)
{
  if (str[count->i + 1] == 'h' && str[count->i + 2] == 'd')
    {
      count->n = my_print_short_nbr(va_arg(*ap, int), count->n);
      count->i = count->i + 3;
    }
}
