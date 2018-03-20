/*
** data.h for data in /home/antoin_g/rendu/Unix/PSU_2015_tetris
**
** Made by Loïs
** Login   <antoin_g@lois-HP-EliteBook-840-G2>
**
** Started on  Thu Mar  3 01:46:44 2016 Loïs
** Last update Sun Mar 20 23:16:45 2016 Loïs
*/

#ifndef DATA_H_
# define DATA_H_

# include <time.h>
# include <stdbool.h>
# include <sys/types.h>

int	g_time;
int	g_rotate;
bool	g_pause;

typedef struct	s_opt
{
  int		level;
  int		map_row;
  int		map_col;
  bool		debug;
  bool		hide_next;
  char		*key_l;
  char		*key_r;
  char		*key_turn;
  char		*key_drop;
  char		*key_hold;
  char		*key_fast;
  char		*key_quit;
  char		*key_pause;
}		t_opt;

typedef struct	s_mino
{
  int		width;
  int		height;
  int		color;
  bool		***piece;
  char		*name;
  struct s_mino	*first;
  struct s_mino	*prev;
  struct s_mino	*next;
}		t_mino;

typedef struct	s_info
{
  int		col;
  int		max;
  int		line;
  int		sidex;
  int		sidey;
  int		score;
  int		level;
  int		advance;
  bool		o;
  char		*key;
  pid_t		son;
  time_t	ref;
  time_t	time;
  t_mino	*tmp;
  t_mino	*next;
  t_mino	*hold;
}		t_info;

typedef struct	s_next
{
  int		w;
  int		h;
  int		i;
  int		sidex;
  int		sidey;
  int		maxi;
}		t_next;

typedef struct	s_hold
{
  int		w;
  int		h;
  int		i;
  int		sidex;
  int		sidey;
  int		maxi;
}		t_hold;

typedef bool	(*t_key)(t_mino *, t_opt *, t_info *, int **);
typedef t_opt	*(*t_ptr)(t_opt *, int *, char **);

#endif /* !DATA_H_ */
