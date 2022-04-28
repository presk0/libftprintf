# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2022/04/28 17:16:26 by supersko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_print_arg.c ft_print_chars.c ft_print_hexa.c ft_print_int.c ft_printf.c ft_strlen_char.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

HEADER = libftprintf.h
LIBFT = libft.a
AR = ar rsu

LIBFT_DIR = ../libft/

CC = gcc
CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)$(LIBFT)
	cp $(LIBFT_DIR)$(LIBFT) .
	$(AR) $(NAME) $(OBJS) $(LIBFT)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
