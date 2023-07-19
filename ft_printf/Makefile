# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keitakah <keitakah@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 11:06:10 by cui               #+#    #+#              #
#    Updated: 2023/07/19 15:40:44 by keitakah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBDIR = libft/
LIBFT = libft/libft.a
SRCS = ft_printf.c ft_put_and_digit.c ft_fetch_cspct.c ft_fetch_diu.c ft_fetch_pxX.c ft_fetch_which.c
OBJS = $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBDIR)
	cp $(LIBFT) $@
	ar -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	make clean -C $(LIBDIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
