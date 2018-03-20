/*
** my_flags_1.c for my_flags_1 in /home/antoin_g/rendu/Unix/PSU_2015_my_printf
** 
** Made by Loïs Antoine
** Login   <antoin_g@epitech.net>
** 
** Started on  Thu Nov  5 22:48:48 2015 Loïs Antoine
** Last update Mon Jan 25 16:43:20 2016 Loïs Antoine
*/

#include <stdarg.h>
#include "print.h"

void	flag_di(va_list *ap, t_count *count, const char *str)
{
  if (str[count->i + 1] == 'd' || str[count->i + 1] == 'i')
    {
      count->i = count->i + 2;
      count->n = my_print_nbr(va_arg(*ap, int), count->n);
    }
}

void	flag_u(va_list *ap, t_count *count, const char *str)
{
  if (str[count->i + 1] == 'u')
    {
      count->i = count->i + 2;
      count->n = my_print_unbr(va_arg(*ap, unsigned int), count->n);
    }
}

void	flag_o(va_list *ap, t_count *count, const char *str)
{
  if (str[count->i + 1] == 'o')
    {
      count->i = count->i + 2;
      count->n = my_printnbr_base(va_arg(*ap, unsigned int), "01234567",
				  count->n);
    }
}

void	flag_x(va_list *ap, t_count *count, const char *str)
{
  if (str[count->i + 1] == 'x')
    {
      count->i = count->i + 2;
      count->n = my_printnbr_base(va_arg(*ap, unsigned int), "0123456789abcdef",
				  count->n);
    }
}

void	flag_X(va_list *ap, t_count *count, const char *str)
{
  if (str[count->i + 1] == 'X')
    {
      count->i = count->i + 2;
      count->n = my_printnbr_base(va_arg(*ap, unsigned int), "0123456789ABCDEF",
				  count->n);
    }
}
