/*
** my_str_isnum.c for str is num in /home/chouik_e/lib/my
**
** Made by Eddy Chouikha
** Login   <chouik_e@epitech.net>
**
** Started on  Mon Oct 12 16:53:11 2015 Eddy Chouikha
** Last update Thu Feb 25 16:43:30 2016 Loïs
*/

int	my_str_isnum(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] < '0' || str[i] > '9')
	return (0);
      ++i;
    }
  return (1);
}
