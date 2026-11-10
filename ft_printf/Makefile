NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
AR = ar
ARFLAGS = rcs
SRCS = ft_printf.c \
		ft_printf_utils.c \
		printers.c \
		writers.c
HDRS = $(SRCS:.c=.h)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
