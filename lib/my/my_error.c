/*
** my_error.c for my_error in /home/antoin_g/rendu/Unix/PSU_2015_my_ls
**
** Made by Loïs Antoine
** Login   <antoin_g@Lois-Labtop>
**
** Started on  Wed Nov 25 17:12:27 2015 Loïs Antoine
** Last update Wed Mar 16 17:08:06 2016 Eddy Chouikha
*/

#include <unistd.h>
#include "tetris.h"
#include "my.h"

void	my_error(const char *str)
{
  write(2, str, my_strlen(str));
  mode_canonique(0, 0);
  exit(EXIT_FAILURE);
}
