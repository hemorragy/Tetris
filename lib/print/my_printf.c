/*
** my_printf.c for my_printf in /home/antoin_g/rendu/Unix/PSU_2015_my_printf
**
** Made by Loïs Antoine
** Login   <antoin_g@epitech.net>
**
** Started on  Mon Nov 30 16:09:54 2015 Loïs Antoine
** Last update Sat Mar 12 00:25:48 2016 Loïs
*/

#include <stdarg.h>
#include <stdlib.h>
#include "print.h"

static void	my_flags(va_list *ap, t_count *count, char *str, t_flags *flags)
{
  int		idx;
  int		check;

  idx = 0;
  check = count->i;
  while (flags[idx] != NULL && count->i == check)
    {
      flags[idx](ap, count, str);
      ++idx;
    }
  if (count->i == check)
    count->i = count->i + my_printf("%c%c", str[count->i], str[count->i + 1]);
}

static void	init_flags(t_flags *flags)
{
  flags[0] = &flag_di;
  flags[1] = &flag_u;
  flags[2] = &flag_o;
  flags[3] = &flag_x;
  flags[4] = &flag_X;
  flags[5] = &flag_b;
  flags[6] = &flag_s;
  flags[7] = &flag_S;
  flags[8] = &flag_c;
  flags[9] = &flag_p;
  flags[10] = &flag_mod;
  flags[11] = &flag_hd;
  flags[12] = &flag_ld;
  flags[13] = &flag_hu;
  flags[14] = &flag_lu;
  flags[15] = NULL;
}

int		my_printf(char *str, ...)
{
  t_flags	flags[16];
  t_count	count;
  va_list	ap;

  count.i = 0;
  count.n = 0;
  va_start(ap, str);
  while (str[count.i] != '\0')
    {
      if (str[count.i] == '%')
	{
	  init_flags(flags);
	  my_flags(&ap, &count, str, flags);
	  --count.i;
	}
      else
	count.n = my_printchar(str[count.i], count.n);
      ++count.i;
    }
  va_end(ap);
  return (count.n);
}
