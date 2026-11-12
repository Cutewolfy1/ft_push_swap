NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Wextra -Werror
SOURCES=ft_printf.c ft_specs.c ft_printf_c.c ft_printf_d.c ft_printf_s.c ft_printf_u.c ft_printf_x.c ft_printf_p.c ft_printf_percent.c utils.c
OBJECTS=$(SOURCES:.c=.o)
LIBFT_DIR=../libft
LIBFT=$(LIBFT_DIR)/libft.a
INCLUDES=-I$(LIBFT_DIR)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	cp $(LIBFT) $@
	ar rs $@ $(OBJECTS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $<

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) $@

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) $@

re: fclean all
