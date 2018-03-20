/*
** print.h for print.h in /home/antoin_g/rendu/Unix/PSU_2015_my_printf
**
** Made by Loïs Antoine
** Login   <antoin_g@epitech.net>
**
** Started on  Thu Nov  5 23:01:51 2015 Loïs Antoine
** Last update Fri Mar 11 18:09:33 2016 Loïs
*/

#ifndef PRINT_H_
# define PRINT_H_

# include <stdarg.h>

typedef struct	s_count
{
  int		n;
  int		i;
}		t_count;

typedef void	(*t_flags)(va_list *, t_count *, const char *);

void	flag_mod(va_list *ap, t_count *count, const char *str);
void	flag_di(va_list *ap, t_count *count, const char *str);
void	flag_ld(va_list *ap, t_count *count, const char *str);
void	flag_hd(va_list *ap, t_count *count, const char *str);
void	flag_lu(va_list *ap, t_count *count, const char *str);
void	flag_hu(va_list *ap, t_count *count, const char *str);
void	flag_u(va_list *ap, t_count *count, const char *str);
void	flag_o(va_list *ap, t_count *count, const char *str);
void	flag_x(va_list *ap, t_count *count, const char *str);
void	flag_X(va_list *ap, t_count *count, const char *str);
void	flag_s(va_list *ap, t_count *count, const char *str);
void	flag_S(va_list *ap, t_count *count, const char *str);
void	flag_c(va_list *ap, t_count *count, const char *str);
void	flag_b(va_list *ap, t_count *count, const char *str);
void	flag_p(va_list *ap, t_count *count, const char *str);
int	my_printnbr_base(const unsigned int nbr, const char *base, int n);
int	my_print_short_unbr(const unsigned short nb, int n);
int	my_print_long_unbr(const unsigned long nb, int n);
int	my_pointnbr_base(long nbr, char *base, int n);
int	my_print_unbr(const unsigned int nb, int n);
int	my_print_short_nbr(short nb, int n);
int	my_printstr(const char *str, int n);
int	my_showfstr(const char *str, int n);
int	my_print_long_nbr(long nb, int n);
int	my_printchar(const char a, int n);
int	my_printlen(const char *str);
int	my_print_nbr(int nb, int n);
int	my_printf(char *str, ...);

#endif /* !PRINT_H_ */
