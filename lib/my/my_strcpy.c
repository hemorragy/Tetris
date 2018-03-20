/*
** my_strcpy.c for my_strcpy in /home/antoin_g/rendu
**
** Made by Loïs Antoine
** Login   <antoin_g@epitech.net>
**
** Started on  Mon Oct  5 10:31:28 2015 Loïs Antoine
** Last update Sat Jan 23 16:37:30 2016 Loïs Antoine
*/

char	*my_strcpy(char *dest, const char *src)
{
  int	a;

  a = 0;
  while (src[a] != '\0')
    {
      dest[a] = src[a];
      ++a;
    }
  dest[a] = 0;
  return (dest);
}
