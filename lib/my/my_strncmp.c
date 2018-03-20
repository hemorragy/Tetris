/*
** my_strcmp.c for my_strcmp in /home/antoin_g/rendu
**
** Made by Loïs Antoine
** Login   <antoin_g@epitech.net>
**
** Started on  Tue Oct  6 11:03:06 2015 Loïs Antoine
** Last update Sat Jan 23 16:41:51 2016 Loïs Antoine
*/

#include "my.h"

int	my_strncmp(const char *s1, const char *s2, const int nb)
{
  int	n;

  n = 0;
  if (s1[n] != s2[n])
    return (0);
  while (s1[n] == s2[n] && s1[n] != '\0' && s2[n] != '\0' && n < nb)
    ++n;
  if (n != nb)
    return (0);
  return (1);
}
