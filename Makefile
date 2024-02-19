SERVER	:= server
CLIENT	:= client

CC	:= cc
CFLAGS	:= -Wextra -Wall -Werror -g3

LIBFT	:= ./lib/libft
PRINTF	:= ./lib/printf

SRCS_CLIENT	:= src/client.c
CLIENT_OBJS	:= $(SRCS_CLIENT:src/%.c=obj/%.o)

SRCS_SERVER	:= src/server.c
SERVER_OBJS	:= $(SRCS_SERVER:src/%.c=obj/%.o)
.SILENT:

GREEN := \033[32m
BLUE := \033[34m
YELLOW := \033[33m
RESET := \033[0m

HEADERS	:= -I ./include -I $(LIBFT)/include -I $(PRINTF)/include
LIBS	:= ${LIBFT}/libft.a $(PRINTF)/libftprintf.a -ldl -lglfw -pthread -lm

all: libft printf $(CLIENT) $(SERVER)

libft:
	$(MAKE) -C ${LIBFT} all

printf:
	$(MAKE) -C ${PRINTF} all


SRCS_SERVER	:= $(addprefix $(SRCS_PATH_SERVER),\
			server.c \
			)
$(CLIENT): $(CLIENT_OBJS)
	printf "$(YELLOW) Compiling client...$(RESET)\n"
	$(CC) $(CLIENT_OBJS) $(LIBS) $(HEADERS) -o $(CLIENT)
	printf "$(GREEN)Done!\n $(RESET)"

$(SERVER): $(SERVER_OBJS)
	printf "$(BLUE)Compiling server...$(RESET)\n"
	$(CC) $(SERVER_OBJS) $(LIBS) $(HEADERS) -o $(SERVER)
	printf "$(GREEN)Done!\n $(RESET)"

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(HEADERS) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf obj

fclean: clean
	rm -rf $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all, clean, fclean, re, libft, printf
