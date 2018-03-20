/*
** opts_flags1.c for tetris in /home/chouik_e/Rendu/TODO/PSU_2015_tetris/srcs
**
** Made by Eddy Chouikha
** Login   <chouik_e@epitech.net>
**
** Started on  Tue Feb 23 16:45:37 2016 Eddy Chouikha
** Last update Sun Mar 20 22:46:18 2016 Loïs
*/

#include "tetris.h"
#include "my.h"

t_opt	*my_set_level(t_opt *opts, int *i, char **av)
{
  if (my_strcmp(av[*i], "-l"))
    {
      if (av[*i + 1] == NULL)
	my_error(INVALID_OPT_VALUE);
      else if (my_str_isnum(av[*i + 1]) == 0)
	my_error(INVALID_OPT_VALUE);
      opts->level = my_getnbr(av[*i + 1]);
      ++*i;
      return (opts);
    }
  else if (my_strncmp(av[*i], "--level=", 8))
    {
      if (my_strlen(av[*i]) < 9)
	my_error(INVALID_OPT_VALUE);
      if (my_str_isnum(&av[*i][8]) == 0)
	my_error(INVALID_OPT_VALUE);
      opts->level = my_getnbr(&av[*i][8]);
      return (opts);
    }
  return (NULL);
}

t_opt	*my_set_key_l(t_opt *opts, int *i, char **av)
{
  if (my_strcmp(av[*i], "-kl"))
    {
      if (av[*i + 1] == NULL)
	my_error(INVALID_OPT_VALUE);
      opts->key_l = my_strdup(av[*i + 1]);
      ++*i;
      return (opts);
    }
  else if (my_strncmp(av[*i], "--key-left=", 11))
    {
      if (my_strlen(av[*i]) < 12)
	my_error(INVALID_OPT_VALUE);
      opts->key_l = my_strdup(&av[*i][11]);
      return (opts);
    }
  return (NULL);
}

t_opt	*my_set_key_r(t_opt *opts, int *i, char **av)
{
  if (my_strcmp(av[*i], "-kr"))
    {
      if (av[*i + 1] == NULL)
	my_error(INVALID_OPT_VALUE);
      opts->key_r = my_strdup(av[*i + 1]);
      ++*i;
      return (opts);
    }
  else if (my_strncmp(av[*i], "--key-right=", 12))
    {
      if (my_strlen(av[*i]) < 13)
	my_error(INVALID_OPT_VALUE);
      opts->key_r = my_strdup(&av[*i][12]);
      return (opts);
    }
  return (NULL);
}

t_opt	*my_set_key_turn(t_opt *opts, int *i, char **av)
{
  if (my_strcmp(av[*i], "-kt"))
    {
      if (av[*i + 1] == NULL)
	my_error(INVALID_OPT_VALUE);
      opts->key_turn = my_strdup(av[*i + 1]);
      ++*i;
      return (opts);
    }
  else if (my_strncmp(av[*i], "--key-turn=", 11))
    {
      if (my_strlen(av[*i]) < 12)
	my_error(INVALID_OPT_VALUE);
      opts->key_turn = my_strdup(&av[*i][11]);
      return (opts);
    }
  return (NULL);
}

t_opt	*my_set_key_drop(t_opt *opts, int *i, char **av)
{
  if (my_strcmp(av[*i], "-kd"))
    {
      if (av[*i + 1] == NULL)
	my_error(INVALID_OPT_VALUE);
      opts->key_drop = my_strdup(av[*i + 1]);
      ++*i;
      return (opts);
    }
  else if (my_strncmp(av[*i], "--key-drop=", 11))
    {
      if (my_strlen(av[*i]) < 12)
	my_error(INVALID_OPT_VALUE);
      opts->key_drop = my_strdup(&av[*i][11]);
      return (opts);
    }
  return (NULL);
}
