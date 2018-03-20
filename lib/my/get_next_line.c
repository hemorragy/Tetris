/*
** get_next_line.c for get_next_line in /home/antoin_g/rendu/C_prog_elem/CPE_2015_getnextline
**
** Made by Loïs Antoine
** Login   <antoin_g@epitech.net>
**
** Started on  Mon Jan  4 14:54:30 2016 Loïs Antoine
** Last update Mon Mar  7 20:56:14 2016 Loïs
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static int	muli(const char *str, const int choice)
{
  int		i;

  i = 0;
  if (choice == 0)
    while (str[i] != 0)
      ++i;
  else if (choice == 1)
    while (str[i] != '\n' && str[i] != 0)
      ++i;
  else
    if (muli(str, 0) != muli(str, 1))
      i = 1;
  return (i);
}

static void	mulc(char *dest, const char *src, const int n)
{
  int		a;

  a = 0;
  while (src[a] != '\0' && a < n)
    {
      dest[a] = src[a];
      ++a;
    }
  dest[a] = 0;
}

static char	*stack_line(char *buffer, t_gnl *gnl, int choice)
{
  if (gnl->line == NULL)
    {
      if (!(gnl->temp = malloc(sizeof(char) * (muli(buffer, choice) + 1))))
	return (NULL);
      mulc(gnl->temp, buffer, muli(buffer, choice));
    }
  else
    {
      if (!(gnl->temp = malloc(sizeof(char) * (muli(buffer, choice) + 2 +
						muli(gnl->line, 0)))))
	return (NULL);
      mulc(gnl->temp, gnl->line, muli(buffer, 0) + muli(gnl->line, 0) + 2);
      free(gnl->line);
      mulc(gnl->temp + muli(gnl->temp, 0), buffer, muli(buffer, choice));
    }
  if (choice == 1)
    {
      mulc(buffer, buffer + muli(buffer, 1) + 1, muli(buffer, 0));
      gnl->test = 1;
    }
  else
    buffer[0] = 0;
  return (gnl->temp);
}

static char	*gnl_next(char *buffer, t_gnl *gnl, const int fd)
{
  if (buffer[0] == 0)
    {
      if (!(gnl->tmp = read(fd, buffer, READ_SIZE)))
	{
	  if (gnl->line == NULL)
	    return (NULL);
	  else
	    gnl->test = 1;
	}
      if (gnl->tmp == -1)
	return (NULL);
      buffer[gnl->tmp] = 0;
    }
  return (buffer);
}

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE + 1] = "";
  t_gnl		gnl;

  gnl.test = 0;
  gnl.line = NULL;
  if (fd == -1)
    buffer[0] = 0;
  else
    {
      while (gnl.test == 0)
	{
	  if (!(gnl_next(buffer, &gnl, fd)) ||
	      !(gnl.line = stack_line(buffer, &gnl, muli(buffer, 2))))
	    return (NULL);
	}
    }
  return (gnl.line);
}
