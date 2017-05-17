##
## Makefile for Makefile in /home/foyart_h/Documents/rendu/UNIX/PSU_2014_minishell1
## 
## Made by Foyart Hugo
## Login   <foyart_h@epitech.net>
## 
## Started on  Mon Jan 19 14:41:02 2015 Foyart Hugo
## Last update Sun Feb  1 15:01:16 2015 Foyart Hugo
##

CC	= gcc

RM	= rm -f

CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -ansi -pedantic
CFLAGS	+= -I.

NAME	= mysh

SRCS	= main.c \
	do_cd.c \
	get_next_line.c \
	my_str_to_word_tab.c \
	my_strcat.c \
	my_strcpy.c \
	my_strcmp.c \
	put.c \
	read_it.c \
	get_path.c \
	do_command.c \
	show_env.c \
	parse_replace_in_env.c \
	write_in_env.c \
	my_fork.c \
	show_tab.c \
	do_env.c \
	do_unset.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re