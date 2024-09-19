# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 11:09:34 by cwon              #+#    #+#              #
#    Updated: 2024/09/19 16:52:40 by cwon             ###   ########.fr        #
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

src = \
		ft_printf.c \
		extract.c \
		convert.c \
		convert_literal.c \
		convert_numeric.c \
		convert_hex.c \
		convert_pointer.c 
		 
obj = $(src:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(lib_path)

all: $(lib) $(NAME)

bonus: all

$(lib):
	make -C $(lib_path)

$(NAME): $(obj) $(lib)
	cp $(lib) $(NAME)
	ar -rcs $(NAME) $(obj)

clean:
	make clean -C $(lib_path)
	rm -f $(obj)

fclean: clean
	make fclean -C $(lib_path)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft bonus