/*
** my_strlen.c for my_strlen in /home/antoin_g/rendu
**
** Made by Loïs Antoine
** Login   <antoin_g@epitech.net>
**
** Started on  Thu Oct  1 19:45:42 2015 Loïs Antoine
** Last update Sat Jan 23 16:16:50 2016 Loïs Antoine
*/

int	my_strlen(const char *str)
{
  int	a;

  a = 0;
  while (str[a] != '\0')
    ++a;
  return (a);
}
