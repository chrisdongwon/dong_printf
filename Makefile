# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 11:09:34 by cwon              #+#    #+#              #
#    Updated: 2024/09/10 11:45:09 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh

.SUFFIXES:
.SUFFIXES: .c .o

NAME = libftprintf.a

lib_path = ./libft
lib = $(lib_path)/libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

src = ft_printf.c
# b-src = 

obj = $(src:.c=.o)
# b-obj = $(b-src:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(lib_path)

all: $(lib) $(NAME)

$(lib):
	make -C $(lib_path)

$(NAME): $(obj) $(lib)
	cp $(lib) $(NAME)
	ar -rcs $(NAME) $(obj)

#bonus: $(b-obj)
#	ar -rcs $(NAME) $(b-obj)

clean:
	make clean -C $(lib_path)
	rm -f $(obj)
#	rm -f $(obj) $(b-obj)

fclean: clean
	make fclean -C $(lib_path)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft
#.PHONY: all clean fclean re libft bonus