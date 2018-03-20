/*
** my_strcomp.c for strcomp in /home/chouik_e/rendu/Piscine_C_J06/ex_06
**
** Made by Eddy Chouikha
** Login   <chouik_e@epitech.net>
**
** Started on  Tue Oct  6 21:08:24 2015 Eddy Chouikha
** Last update Thu Mar 17 03:09:07 2016 Eddy Chouikha
*/

#include <stdlib.h>

int	my_strcmp(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  if (s1 == NULL || s2 == NULL)
    return (0);
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] != s2[i])
	return (0);
      ++i;
    }
  if (s1[i] != s2[i])
    return (0);
  return (1);
}
