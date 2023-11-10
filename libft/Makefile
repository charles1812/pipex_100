# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cspreafi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 12:38:30 by cspreafi          #+#    #+#              #
#    Updated: 2023/11/10 12:00:58 by cspreafi         ###   ########.fr        #
#                                                                              #
# *****************************************************************************#

COMPILE = gcc
CFLAG = -Wall -Werror -Wextra
SRC = ft_isalpha.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_isascii.c \
				ft_isprint.c \
				ft_strlen.c \
				ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_strlcpy.c \
				ft_strlcat.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_atoi.c \
				ft_calloc.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_freetab.c
MAINFILE = main.c
OUTPUT = -o tests
LIBRARY = rc libft.a ft_*.o
NAME = libft.a
OBJ = $(src:.c=.o)
CLEANCMD = rm -rf *.o
FCLEANCMD = rm -rf *.a


#compile all ft at once and put ion a library
$(NAME):$(OBJ)
	$(COMPILE) $(CFLAG) -c $(SRC)
	ar rcs libft.a ft_*.o

all:$(NAME)

#to compile only one ft at the time
%.o:%.c
	$(COMPILE) $(CFLAG) -c $< -o $@

#clear all lib file
clean:
	$(CLEANCMD)

#clear all .o file
fclean: clean
	$(FCLEANCMD)

re: fclean all
