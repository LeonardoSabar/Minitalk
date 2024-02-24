SERVER	:= server
CLIENT	:= client

BONUS_SERVER := server_bonus
BONUS_CLIENT := client_bonus

CC	:= cc
CFLAGS	:= -Wextra -Wall -Werror -g3

LIBFT	:= ./lib/libft
PRINTF	:= ./lib/printf

SRCS_CLIENT	:= src/client.c
CLIENT_OBJS	:= $(SRCS_CLIENT:src/%.c=obj/%.o)

SRCS_SERVER	:= src/server.c
SERVER_OBJS	:= $(SRCS_SERVER:src/%.c=obj/%.o)

SRCS_CLIENT_BONUS := bonus/client_bonus.c
CLIENT_BONUS_OBJS := $(SRCS_CLIENT_BONUS:bonus/%.c=obj_bonus/%.o)

SRCS_SERVER_BONUS := bonus/server_bonus.c
SERVER_BONUS_OBJS := $(SRCS_SERVER_BONUS:bonus/%.c=obj_bonus/%.o)
.SILENT:

GREEN := \033[32m
BLUE := \033[34m
YELLOW := \033[33m
RESET := \033[0m

HEADERS	:= -I ./include -I $(LIBFT)/include -I $(PRINTF)/include
LIBS	:= ${LIBFT}/libft.a $(PRINTF)/libftprintf.a -ldl -lglfw -pthread -lm

all: libft printf $(CLIENT) $(SERVER)

bonus: libft printf $(BONUS_CLIENT) $(BONUS_SERVER)

libft:
	$(MAKE) -C ${LIBFT} all

printf:
	$(MAKE) -C ${PRINTF} all

$(CLIENT): $(CLIENT_OBJS)
	printf "$(YELLOW) Compiling client...$(RESET)\n"
	$(CC) $(CLIENT_OBJS) $(LIBS) $(HEADERS) -o $(CLIENT)
	printf "$(GREEN)Done!\n $(RESET)"

$(SERVER): $(SERVER_OBJS)
	printf "$(BLUE)Compiling server...$(RESET)\n"
	$(CC) $(SERVER_OBJS) $(LIBS) $(HEADERS) -o $(SERVER)
	printf "$(GREEN)Done!\n $(RESET)"

$(BONUS_CLIENT): $(CLIENT_BONUS_OBJS)
	printf "$(YELLOW) Compiling client bonus...$(RESET)\n"
	$(CC) $(CLIENT_BONUS_OBJS) $(LIBS) $(HEADERS) -o $(BONUS_CLIENT)
	printf "$(GREEN)Done!\n $(RESET)"

$(BONUS_SERVER): $(SERVER_BONUS_OBJS)
	printf "$(BLUE) Compiling server bonus...$(RESET)\n"
	$(CC) $(SERVER_BONUS_OBJS) $(LIBS) $(HEADERS) -o $(BONUS_SERVER)
	printf "$(GREEN)Done!\n $(RESET)"

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(HEADERS) $(CFLAGS) -o $@ -c $<

obj_bonus/%.o: bonus/%.c
	mkdir -p obj_bonus
	$(CC) $(HEADERS) $(CFLAGS) -o $@ -c $<

clean:
	rm -rf obj

fclean: clean
	rm -rf $(CLIENT) $(SERVER) $(BONUS_CLIENT) $(BONUS_SERVER)

re: fclean all

.PHONY: all, clean, fclean, re, libft, printf
