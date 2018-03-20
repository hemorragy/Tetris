##
## Makefile for all in /home/chouik_e/Scripts/Fichiers
##
## Made by Eddy Chouikha
## Login   <chouik_e@epitech.net>
##
## Started on  Thu Jan 28 18:20:51 2016 Eddy Chouikha
## Last update Thu Mar 17 04:40:20 2016 Loïs
##

RM	= 	rm -f

NAME	=	libmy.a

SRCS 	=	my_getnbr.c \
		my_str_nisnum.c \
		get_next_line.c \
		my_str_isnum.c \
		my_strcpint.c \
		my_strsort.c \
		my_strncmp.c \
		my_strncpy.c \
		my_strcmp.c \
		my_strdup.c \
		my_strcpy.c \
		my_strlen.c \
		my_error.c \
		xmalloc.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+= -W -Wall -Wextra -Werror
CFLAGS	+= -pedantic -ansi -I../../include

all:	$(NAME)

$(NAME):	$(OBJS)
		ar rc $(NAME) $(OBJS)
		ranlib $(NAME)
		cp $(NAME) ..

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
