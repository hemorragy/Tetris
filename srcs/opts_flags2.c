/*
** opts_flags2.c for tetris in /home/chouik_e/Rendu/TODO/PSU_2015_tetris/srcs
**
** Made by Eddy Chouikha
** Login   <chouik_e@epitech.net>
**
** Started on  Tue Feb 23 16:45:23 2016 Eddy Chouikha
** Last update Sun Mar 20 22:46:51 2016 Loïs
*/

#include "tetris.h"
#include "my.h"

t_opt	*my_set_key_quit(t_opt *opts, int *i, char **av)
{
  if (my_strcmp(av[*i], "-kq"))
    {
      if (av[*i + 1] == NULL)
	my_error(INVALID_OPT_VALUE);
      opts->key_quit = my_strdup(av[*i + 1]);
      ++*i;
      return (opts);
    }
  else if (my_strncmp(av[*i], "--key-quit=", 11))
    {
      if (my_strlen(av[*i]) < 12)
	my_error(INVALID_OPT_VALUE);
      opts->key_quit = my_strdup(&av[*i][11]);
      return (opts);
    }
  return (NULL);
}

t_opt	*my_set_key_pause(t_opt *opts, int *i, char **av)
{
  if (my_strcmp(av[*i], "-kp"))
    {
      if (av[*i + 1] == NULL)
	my_error(INVALID_OPT_VALUE);
      opts->key_quit = my_strdup(av[*i + 1]);
      ++*i;
      return (opts);
    }
  else if (my_strncmp(av[*i], "--key-pause=", 12))
    {
      if (my_strlen(av[*i]) < 13)
	my_error(INVALID_OPT_VALUE);
      opts->key_pause = my_strdup(&av[*i][12]);
      return (opts);
    }
  return (NULL);
}

t_opt	*my_set_map_size(t_opt *opts, int *i, char **av)
{
  int	tmp;
  char	*rows;

  tmp = 0;
  rows = NULL;
  if (my_strncmp(av[*i], "--map-size=", 11))
    {
      while (av[*i][tmp] != ',' && av[*i][tmp])
	++tmp;
      if (av[tmp] + 1 == 0 || tmp < 12)
	my_error(INVALID_OPT_VALUE);
      rows = my_strncpy(rows, &av[*i][11], tmp - 11);
      if ((my_str_isnum(rows) == 0) || (my_str_isnum(&av[*i][tmp + 1]) == 0))
	my_error(INVALID_OPT_VALUE);
      opts->map_row = my_getnbr(rows);
      opts->map_col = my_getnbr(&av[*i][tmp + 1]);
      return (opts);
    }
  return (NULL);
}

t_opt	*my_set_hide_next(t_opt *opts, int *i, char **av)
{
  if (my_strcmp(av[*i], "-w") || my_strcmp(av[*i], "--without-next"))
    {
      opts->hide_next = 1;
      return (opts);
    }
  return (NULL);
}

t_opt	*my_set_debug(t_opt *opts, int *i, char **av)
{
  if (my_strcmp(av[*i], "-d") || my_strcmp(av[*i], "--debug"))
    {
      opts->debug = 1;
      return (opts);
    }
  return (NULL);
}
