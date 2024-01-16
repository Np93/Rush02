# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trossel <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/24 10:17:15 by trossel           #+#    #+#              #
#    Updated: 2021/07/25 19:59:38 by trossel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = rush-02

INCLUDES_DIR = includes
INCLUDES = dict.h

SRCS_DIR = srcs
_SRCS = main.c \
		parse_dict.c \
		default_dict.c \
		free_dict.c \
		parse_key_line.c \
		parse_number.c \
		ft_strjoin.c \
		dict.c \
		print_number_in_english.c \
		print_number_1000.c \
		ft.c
SRCS = $(addprefix $(SRCS_DIR)/, $(_SRCS))

_OBJS= $(patsubst %.c,%.o,$(_SRCS))
OBJS = $(addprefix $(SRCS_DIR)/, $(_OBJS))

CFLAGS = -Wall -Wextra -Werror -I$(INCLUDES_DIR)

vpath %.c $(SRCS_DIR)
vpath %.o $(SRCS_DIR)

.PHONY : all clean fclean re objects

all: $(NAME)

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	$(CC) -c -o $@ $^ $(CFLAGS)

$(NAME): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
