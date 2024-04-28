SRCS = ft_printf.c ft_atoi.c
OBJS = $(SRCS:.c=.o)
NAMESR = server
NAMECL = client  

CFLAGS = -Wall -Wextra -Werror

all: server client

$(NAMESR): server.o $(OBJS)
	gcc $(CFLAGS) $^ -o $@

$(NAMECL): client.o $(OBJS)
	gcc $(CFLAGS) $^ -o $@

$(OBJS): %.o: %.c
	gcc $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf client server

re: fclean all

.PHONY: all clean fclean re