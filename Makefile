# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:52:39 by cwon              #+#    #+#              #
#    Updated: 2024/09/08 17:41:12 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# output name
# library extension: .lib for Windows, .a or .so for Unix
NAME = libft.a

# compiler
CC = cc

# compile flags
CFLAGS = -Wall -Wextra -Werror

# c files to compile
src = \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_strjoin.c ft_substr.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# bonus c files
b-src = \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
	ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

# object files
# variable declaration with substitution
# files with extension .c changed to .o
obj = $(src:.c=.o)
b-obj = $(b-src:.c=.o)

# target all
# if library exists, clean first
# else, compile then build library using ar command
all: $(NAME)

# use cc to compile c files and the object files.
# % wildcard for pattern matching, * wildcard for name matching from shell
# $< for first prerequisite, meaning c files in this case
# $@ for the target name, so obj files in this case
# previously - %.o: %.c libft.h Makefile
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ar flags:
# r for inserting files into archive,
# c for creating archive,
# s for indexing the files in the archive
$(NAME): $(obj)
	ar -rcs $(NAME) $(obj)

# $? for prerequisites newer than the target
bonus: $(b-obj)
	ar -rcs $(NAME) $^

# clean will remove object files
clean:
	rm -f $(obj) $(b-obj)

# fclean will remove object and c files
fclean: clean 
	rm -f $(NAME)

# re for rebuild
re: fclean $(NAME)

# if a target name happens to match a file name in the directory,
# it removes so that the targets are interpreted correctly in the makefile
.PHONY: all bonus clean fclean re