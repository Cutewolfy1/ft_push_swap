CC = cc
CFLAGS = -Wall -Wextra -Werror -g
TARGET = push_swap
SRCS = push_swap.c \
		stack.c \
		simple_algo.c \
		argparser.c \
		algorithm.c \
		operation.c
HDRS = $(SRCS:.c=.h)
OBJS = $(SRCS:.c=.o)
INCL = -I$(LIBFTDIR) -I$(PRINTFDIR)
LIBFTDIR = libft
LIBFT = libft.a
PRINTFDIR = ft_printf
PRINTF = libftprintf.a

all: $(TARGET)

$(TARGET): $(OBJS) $(LIBFTDIR)/$(LIBFT) $(PRINTFDIR)/$(PRINTF)
	$(CC) $(CFLAGS) -o $@ $^

$(PRINTFDIR)/$(PRINTF):
	$(MAKE) -C $(PRINTFDIR) $(PRINTF)

$(LIBFTDIR)/$(LIBFT):
	$(MAKE) -C $(LIBFTDIR) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) $(INCL) -c $< -o $@
	
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFTDIR) $@
	$(MAKE) -C $(PRINTFDIR) $@

fclean: clean
	rm -f $(TARGET)
	$(MAKE) -C $(LIBFTDIR) $@
	$(MAKE) -C $(PRINTFDIR) $@

re: fclean all

.PHONY: all clean fclean re
