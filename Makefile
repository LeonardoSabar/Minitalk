NAME	:= server
NAME2	:= client
CFLAGS	:= -Wextra -Wall -Werror -g3
LIBFT	:= ./lib/libft
PRINTF	:= ./lib/printf
SRCS_PATH	:= ./src/
.SILENT:

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

COUNT = 0
HEADERS	:= -I ./include -I $(LIBFT)/include -I $(PRINTF)/include
LIBS	:= ${LIBFT}/libft.a $(PRINTF)/libftprintf.a -ldl -lglfw -pthread -lm
SRCS	:= $(addprefix $(SRCS_PATH),\
			client.c \
			server\)

OBJS	:= ${SRCS:%.c=%.o}

all: libft printf $(NAME)

libft:
	$(MAKE) -C ${LIBFT} all

printf:
	$(MAKE) -C ${PRINTF} all

%.o: %.c
	$(eval COUNT=$(shell expr $(COUNT) + 1))
	$(CC) $(HEADERS) $(CFLAGS) -o $@ -c $<
	printf "Compiling %d%%\r" $$(echo $$(($(COUNT) * 100 / $(words $(SRCS)))))

$(NAME): $(OBJS)
	printf "$(YELLOW)Compiling server...$(RESET)\n"
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	printf "$(GREEN)Done!\n $(RESET)"

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re, libft, printf
