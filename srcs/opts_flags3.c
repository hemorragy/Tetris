/*
** opts_flags2.c for tetris in /home/chouik_e/Rendu/TODO/PSU_2015_tetris/srcs
**
** Made by Eddy Chouikha
** Login   <chouik_e@epitech.net>
**
** Started on  Tue Feb 23 16:45:23 2016 Eddy Chouikha
** Last update Sat Mar 19 14:48:31 2016 Eddy Chouikha
*/

#include "tetris.h"
#include "my.h"

t_opt	*my_set_key_hold(t_opt *opts, int *i, char **av)
{
  if (my_strcmp(av[*i], "-kh"))
    {
      if (av[*i + 1] == NULL)
	my_error(INVALID_OPT_VALUE);
      opts->key_hold = my_strdup(av[*i + 1]);
      ++*i;
      return (opts);
    }
  else if (my_strncmp(av[*i], "--key-hold=", 11))
    {
      if (my_strlen(av[*i]) < 12)
	my_error(INVALID_OPT_VALUE);
      opts->key_hold = my_strdup(&av[*i][11]);
      return (opts);
    }
  return (NULL);
}

t_opt	*my_set_key_fast(t_opt *opts, int *i, char **av)
{
  if (my_strcmp(av[*i], "-kf"))
    {
      if (av[*i + 1] == NULL)
	my_error(INVALID_OPT_VALUE);
      opts->key_fast = my_strdup(av[*i + 1]);
      ++*i;
      return (opts);
    }
  else if (my_strncmp(av[*i], "--key-fast=", 11))
    {
      if (my_strlen(av[*i]) < 12)
	my_error(INVALID_OPT_VALUE);
      opts->key_fast = my_strdup(&av[*i][11]);
      return (opts);
    }
  return (NULL);
}
