NAME1 = server
NAME2 = client

PRTF = ft_printf/libftprintf.a
LIBFT = ft_printf/libft/libft.a

SRC1 = server.c
SRC2 = client.c

PRTFDIR = ft_printf/

CC = cc
CFLAGS = -Wall -Wextra -Werror
IF = -I$(INC_DIR)
INC_DIR = include/


all: $(NAME1) $(NAME2)

$(NAME1): $(SRC1) $(PRTF)
	$(CC) $(CFLAGS) $(IF) $? -o $@

$(NAME2): $(SRC2) $(PRTF)
	$(CC) $(CFLAGS) $(IF) $? -o $@

$(PRTF):
	make -C $(PRTFDIR)

clean:
	make clean -C $(PRTFDIR)

fclean: clean
	rm $(NAME1) $(NAME2) $(PRTF) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re


#cc -I[dir_name]: cファイル内で、ヘッダファイルをパス指定なしで参照してくれる。[dir_name]にヘッダファイルが入っているから。
#