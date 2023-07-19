NAME1 = server
NAME2 = client
PRTFDIR = ft_printf/
PRTF = ft_printf/libftprintf.a
SRC1 = server.c 
SRC2 = client.c
CC = cc
CFLAGS = -Wall -Wextra -Werror


all: $(NAME1) $(NAME2)

$(NAME1): $(SRC1)
	make -C $(PRTFDIR)
	$(CC) $(CFLAGS) $? $(PRTF) -o $@

$(NAME2): $(SRC2)
	make -C $(PRTFDIR)
	$(CC) $(CFLAGS) $? $(PRTF) -o $@

clean:
	make clean -C $(PRTFDIR)

fclean: clean
	make fclean -C $(PRTFDIR)
	rm $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re