NAME = minitalk.a
PRTFDIR = ft_printf/
PRTF = ft_printf/libftprintf.a
SRCS = server.c client.c
OBJS = $(SRCS:.c=)
CC = cc
CFLAGS = -Wall -Wextra -Werror


all: 
	make -C $(PRTFDIR)
	$(CC) $(CFLAGS) server.c $(PRTF) -o server
	$(CC) $(CFLAGS) client.c $(PRTF) -o client

clean:
	make clean -C $(PRTFDIR)
	rm -f $(OBJS)

fclean: clean
	make fclean -C $(PRTFDIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re