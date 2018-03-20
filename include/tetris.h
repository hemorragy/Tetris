/*
** tetris.h for tetris in /home/chouik_e/Rendu/TODO/PSU_2015_tetris
**
** Made by Eddy Chouikha
** Login   <chouik_e@chouik-e-pc>
**
** Started on  Mon Feb 22 14:26:57 2016 Eddy Chouikha
** Last update Sun Mar 20 23:18:27 2016 Loïs
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# include <dirent.h>
# include "data.h"

t_mino	*switch_hold(t_mino *mino, t_info *info);
t_mino	*get_tetrimino(const t_opt *opts);
t_mino	*take_new_piece(t_mino *mino);
t_opt	*my_set_hide_next(t_opt *opts, int *i, char **av);
t_opt	*my_set_key_pause(t_opt *opts, int *i, char **av);
t_opt	*my_set_key_quit(t_opt *opts, int *i, char **av);
t_opt	*my_set_map_size(t_opt *opts, int *i, char **av);
t_opt	*my_set_key_turn(t_opt *opts, int *i, char **av);
t_opt	*my_set_key_drop(t_opt *opts, int *i, char **av);
t_opt   *my_set_key_hold(t_opt *opts, int *i, char **av);
t_opt	*my_set_key_fast(t_opt *opts, int *i, char **av);
t_opt	*my_set_key_r(t_opt *opts, int *i, char **av);
t_opt	*my_set_key_l(t_opt *opts, int *i, char **av);
t_opt	*my_set_debug(t_opt *opts, int *i, char **av);
t_opt	*my_set_level(t_opt *opts, int *i, char **av);
char	*wait_for_key(int vmin);
void	print_tray(const t_mino *mino, const t_opt *opts,
		   t_info *info, const int **tray);
void	the_rotate(t_mino *mino, const t_opt *opts, t_info *info, int **tray);
void	aff_next(const t_mino *mino, const t_opt *opts, const t_info *info);
void	aff_hold(const t_mino *mino, const t_opt *opts, const t_info *info);
void	action_curse(t_mino *mino, t_opt *opts, t_info *info, int **tray);
void	check_key(t_mino *mino, t_opt *opts, t_info *info, int **tray);
void	clean_it(const t_opt *opts, const t_info *info, int **tray);
void	supress_line(int **tray, t_opt *opts, t_info *info);
void	set_link_value(t_mino *mino, struct dirent *read);
void	debug_mode(const t_opt *opts, const t_mino *mino);
void	aff_time(time_t ref, time_t time, int x, int y);
void	create_curse(t_mino *mino, t_opt *opts);
void	check_args(char **av, t_opt *opts);
void	rotate_pieces(t_mino *mino, int i);
void	check_validate_form(t_mino *mino);
void	if_valid_mino(const t_mino *mino);
void	display_mino(const t_mino *mino);
void	free_minos(t_mino *mino, int n);
void	is_double(const t_opt *opts);
void	free_tab(int **taab, int y);
void	my_free_mino(t_mino *mino);
void	init_opts(t_opt *opts);
void	set_clr_pair(void);
bool	place_piece_center(const t_mino *mino, const t_opt *opts,
			   t_info *info, int **tray);
bool	go_right(const t_mino *mino, const t_opt *opts,
		 t_info *info, int **tray);
bool	go_down(t_mino *mino, const t_opt *opt, t_info *info, int **tray);
bool	key_rotate(t_mino *mino, t_opt *opts, t_info *info, int **tray);
bool	key_pause(t_mino *mino, t_opt *opts, t_info *info, int **tray);
bool	key_fast(t_mino *mino, t_opt *opts, t_info *info, int **tray);
bool	key_drop(t_mino *mino, t_opt *opts, t_info *info, int **tray);
bool	check_for_next_thing(const bool *piece, int idx, int width);
bool	go_left(const t_mino *mino, t_info *info, int **tray);
bool	creat_link(t_mino *tmp, t_mino *current, int test);
bool	extra_term_size(const t_opt *opts, t_info *info);
int	**creat_tray(const t_opt *opts, const t_info *info);
int	find_space(const char *str, int *idx);
int	mode_canonique(int i, int vmin);
int	end_space(const char *str);

# define INVALID_OPT ("Error : invalid option(s)\n")
# define INVALID_OPT_VALUE ("Error : invalid option(s) value(s)\nTry --help\n")
# define INVALID_TERM ("This term can't be used for tetris\n")
# define NO_ARROWS_FOUND ("Can't found arrow keys in this term\n")
# define SAME_KEYS_SET ("Some keys have the same value\n")
# define READ_FAILED ("Read Failed\n")

#endif /* !TETRIS_H_ */
