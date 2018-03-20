/*
** my.h for my in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Mon Feb 22 19:56:48 2016 Loïs
** Last update Thu Mar 17 04:40:15 2016 Loïs
*/

#ifndef MY_H_
# define MY_H_

# include <stdlib.h>

void	*xmalloc(size_t size);
void	my_error(const char *str);
int	*my_strcpint(int * const dest, int const * const src, int size);
int	my_strncmp(const char *s1, const char *s2, const int n);
int	my_str_nisnum(const char *str, const int n);
int	my_strsort(const char *s1, const char *s2);
int	my_strcmp(const char *s1, const char *s2);
int	my_str_isnum(const char *str);
int	my_strlen(const char *str);
int	my_getnbr(const char *str);
char	*my_strncpy(char *dest, const char *src, const int n);
char	*my_strcpy(char *dest, const char *src);
char	*my_strdup(const char *src);

#endif /* !MY_H_ */
