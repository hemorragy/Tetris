##
## Makefile for Makefile in /home/antoin_g/rendu/lib/include
##
## Made by Loïs Antoine
## Login   <antoin_g@epitech.net>
##
## Started on  Sat Nov  7 13:34:24 2015 Loïs Antoine
## Last update Mon Feb  8 16:46:44 2016 Loïs
##

RM	= 	rm -f

NAME	= 	libprint.a

SRCS	= 	my_printf.c \
		my_print_nbr_next.c \
		my_printchar.c \
		my_print_nbr.c \
		my_flags_1.c \
		my_flags_2.c \
		my_flags_3.c

OBJS	= 	$(SRCS:.c=.o)

CFLAGS  += 	-W -Wall -Wextra -Werror -I../../include

all: 		$(NAME)

$(NAME): 	$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
		cp $(NAME) ../

clean:
		$(RM) $(OBJS)

fclean: 	clean
		$(RM) $(NAME)
		$(RM) ../$(NAME)

.PHONY:		all clean fclean re
