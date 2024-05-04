NAME = serverclient
SRCS = ft_printf.c
OBJS = $(SRCS:.c=.o)
SERVER = server
CLIENT = client  

CFLAGS = -Wall -Wextra -Werror

NAME = $(CLIENT) $(SERVER)

all: $(NAME)

$(SERVER): server.o $(OBJS)
	gcc $(CFLAGS) server.o $(OBJS) -o $(SERVER)

$(CLIENT): client.o $(OBJS)
	gcc $(CFLAGS) client.o $(OBJS) -o $(CLIENT)

clean:
	rm -rf server.o client.o $(OBJS)

fclean: clean
	rm -rf client server

re: fclean all

.PHONY: all clean fclean re