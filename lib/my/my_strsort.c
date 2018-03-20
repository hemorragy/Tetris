/*
** my_strcomp.c for strcomp in /home/chouik_e/rendu/Piscine_C_J06/ex_06
**
** Made by Eddy Chouikha
** Login   <chouik_e@epitech.net>
**
** Started on  Tue Oct  6 21:08:24 2015 Eddy Chouikha
** Last update Thu Feb 25 14:20:28 2016 Loïs
*/

int	my_strsort(const char *s1, const char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != 0 && s2[i] != 0)
    {
      if (s1[i] != s2[i])
	return (s1[i] - s2[i]);
      ++i;
    }
  if (s1[i] != s2[i])
    return (s1[i] - s2[i]);
  return (0);
}
