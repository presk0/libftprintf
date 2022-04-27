# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 15:16:38 by supersko          #+#    #+#              #
#    Updated: 2022/04/27 21:26:19 by supersko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_print_arg.c ft_print_chars.c ft_print_hexa.c ft_print_int.c ft_printf.c ft_strlen_char.c

OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a

HEADER = libftprintf.h
LIBFT = libft.a
AR = ar rsu

SRC_DIR = ./src/
INC_DIR = ./include/
LIBFT_DIR = ../libft/

CC = gcc
CFLAGS += -Wall -Werror -Wextra
CPPFLAGS += -I$(INC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

$(NAME):  $(OBJS) $(LIBFT_DIR)$(LIBFT)
	cp $(LIBFT_DIR)$(LIBFT) .
	$(AR) $(LIBFT) $(OBJS)

	$(CC) $(CFLAGS) -c $(SRCS) $(HEADER)
	ar rc $(NAME) $(OBJS)

$(LIBFT_DIR)$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# $(NAME): $(DIRS) $(OBJS) $(LIBFT_DIR)$(LIBFT)
# 	$(CP) $(LIBFT_DIR)$(LIBFT) $(OUT_DIR)
# 	$(AR) $(OUT_DIR)$(LIBFT) $(OBJS)
# 	$(MV) $(OUT_DIR)$(LIBFT) $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus:
	$(CC) $(CFLAGS) -c $(SRCS) $(HEADER)
	ar rc $(NAME) $(OBJS)

test:
	$(CC) $(SRCS) $(SRCS_BONUS) $(HEADER)
	./a.out
	rm a.out

debug:
	$(CC) -g $(SRCS) $(SRCS_BONUS) $(HEADER)
	lldb a.out
	rm a.out

.PHONY: all clean fclean re
