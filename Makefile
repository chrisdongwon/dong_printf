# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cwon <cwon@student.42bangkok.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/03 16:52:39 by cwon              #+#    #+#              #
#    Updated: 2024/09/09 15:38:58 by cwon             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# output name
# library extension: .lib for Windows, .a or .so for Unix
NAME = libftprintf.a

# compiler
CC = cc

# compile flags
CFLAGS = -Wall -Wextra -Werror

# c files to compile
#src = 

# bonus c files
# b-src = 

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