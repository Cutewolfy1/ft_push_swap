CC = cc
CFLAGS = -Wall -Wextra -Werror -g
TARGET = push_swap

SRCS = push_swap.c \
		utils.c
HDRS = $(SRCS:.c=.h)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
