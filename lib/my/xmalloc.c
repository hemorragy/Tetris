/*
** xmalloc.c for xmalloc in /home/antoin_g/rendu/Unix/PSU_2015_minishell1
**
** Made by Loïs Antoine
** Login   <antoin_g@Lois-Labtop>
**
** Started on  Fri Jan 15 00:42:36 2016 Loïs Antoine
** Last update Mon Feb 22 20:04:23 2016 Loïs
*/

#include "my.h"

void	*xmalloc(size_t size)
{
  void	*tmp;

  tmp = malloc(size);
  if (tmp == NULL)
    my_error("Memory allocation error\n");
  return (tmp);
}
