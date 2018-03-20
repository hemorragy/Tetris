/*
** my_strdup.c for my_strdup in /home/antoin_g/rendu/Unix/PSU_2015_minishell1
**
** Made by Loïs Antoine
** Login   <antoin_g@Lois-Labtop>
**
** Started on  Wed Jan 20 18:48:21 2016 Loïs Antoine
** Last update Sat Jan 23 16:39:39 2016 Loïs Antoine
*/

#include "my.h"

char	*my_strdup(const char *str)
{
  char	*dup;

  dup = xmalloc(sizeof(char) * (my_strlen(str) + 1));
  dup = my_strcpy(dup, str);
  return (dup);
}
