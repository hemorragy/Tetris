##
## Makefile for all in /home/chouik_e/Scripts/Fichiers
##
## Made by Eddy Chouikha
## Login   <chouik_e@epitech.net>
##
## Started on  Thu Jan 28 18:21:03 2016 Eddy Chouikha
## Last update Sun Mar 20 22:55:25 2016 Loïs
##

CC		= gcc

RM		= rm -f

LINK		= $(MAKE) -C

CFLAGS          = -lmy -lprint -lncurses -ltinfo -L./lib
CFLAGS          += -Wextra -Wall -Werror
CFLAGS          += -ansi -pedantic
CFLAGS          += -Iinclude -D_POSIX_SOURCE -D_BSD_SOURCE

NAME		= tetris

SRCS		= srcs/main.c \
		srcs/stock_tetrimino.c \
		srcs/mino_side_moves.c \
		srcs/get_tetrimino.c \
		srcs/game_progress.c \
		srcs/create_tetris.c \
		srcs/my_tray_tools.c \
		srcs/display_mino.c \
		srcs/delete_line.c \
		srcs/opts_flags1.c \
		srcs/opts_flags2.c \
		srcs/opts_flags3.c \
		srcs/debug_mino.c \
		srcs/mino_move.c \
		srcs/dat_frees.c \
		srcs/key_tools.c \
		srcs/rotation.c \
		srcs/the_hold.c \
		srcs/options.c \
		srcs/my_tray.c \
		srcs/debug.c \
		srcs/utils.c \
		srcs/key.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME) $(LIB1) $(LIB2)

$(NAME):	$(OBJS)
		$(LINK) ./lib/my
		$(LINK) ./lib/print
		$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(LINK) ./lib/my clean
	$(LINK) ./lib/print clean

fclean:	clean
	$(RM) $(NAME)
	$(LINK) ./lib/my fclean
	$(LINK) ./lib/print fclean

re: fclean all

.PHONY: all clean fclean re
