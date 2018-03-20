/*
** my_getnbr.c for getnbr in /home/chouik_e/rendu/Piscine_C_colles-Semaine_02
**
** Made by Eddy Chouikha
** Login   <chouik_e@epitech.net>
**
** Started on  Sat Oct 10 13:04:10 2015 Eddy Chouikha
** Last update Fri Feb 26 00:13:37 2016 Loïs
*/

#include "my.h"

static int	first_nb(const char *str)
{
  int		i;

  i = 0;
  while (str[i] != 0 && (str[i] < '0' || str[i] > '9'))
    ++i;
  return (i);
}

static int	nb_lenght(const char *str)
{
  int		i;

  i = first_nb(str);
  while (str[i] >= '0' && str[i] <= '9')
    ++i;
  --i;
  return (i);
}

static int	str_to_nb(const char *str)
{
  int		first_nbr;
  int		last_nbr;
  long		first_mult;
  long		tmp;

  first_nbr = first_nb(str);
  last_nbr = nb_lenght(str);
  first_mult = 1;
  tmp = 0;
  while (first_nbr < last_nbr)
    {
      first_mult = first_mult * 10;
      ++first_nbr;
    }
  first_nbr = first_nb(str);
  while (first_nbr <= last_nbr)
    {
      tmp = tmp + ((str[first_nbr] - 48) * first_mult);
      ++first_nbr;
      first_mult = first_mult / 10;
    }
  first_nbr = first_nb(str) - 1;
  if (!(tmp < 2147483648 || (tmp == 2147483648 && str[first_nbr] == '-')))
    return (0);
  return (tmp);
}

int	my_getnbr(const char *str)
{
  long	tmp;
  int	nbr;

  tmp = str_to_nb(str);
  nbr = 0;
  if (first_nb(str) - 1 >= 0 && str[first_nb(str) - 1] == '-')
    nbr = -tmp;
  else
    nbr = tmp;
  if (str == NULL)
    return (0);
  else
    return (nbr);
}
