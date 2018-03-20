/*
** my_strncpy.c for strncpy in /home/chouik_e/rendu/Piscine_C_J06
**
** Made by Eddy Chouikha
** Login   <chouik_e@epitech.net>
**
** Started on  Mon Oct  5 16:20:33 2015 Eddy Chouikha
** Last update Sat Mar 19 19:10:50 2016 Eddy Chouikha
*/

#include "my.h"

char	*my_strncpy(char *dest, const char *src, const int n)
{
  int	i;

  i = 0;
  if (dest == NULL)
    dest = xmalloc(n + 1);
  while (i < n && src[i] != 0)
    {
      dest[i] = src[i];
      ++i;
    }
  dest[i] = 0;
  return (dest);
}
