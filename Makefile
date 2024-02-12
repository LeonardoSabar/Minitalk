NAME	:= minitalk
CFLAGS	:= -Wextra -Wall -Werror -g3
LIBFT	:= ./lib/libft
PRINTF	:= ./lib/printf
SRCS_PATH	:= ./src/
# NAME_BONUS	:=
# SRCS_PATH_BONUS	:= ./bonus/
.SILENT:

GREEN = \033[32m
YELLOW = \033[33m
RESET = \033[0m

# ifdef WITH_BONUS
# 	NAME	:= $(NAME_BONUS)
# 	SRCS	:= $(SRCS_BONUS)
# 	OBJS	:= $(OBJS_BONUS)
# endif

HEADERS	:= -I ./include -I $(LIBFT)/include -I $(PRINTF)/include
LIBS	:= ${LIBFT}/libft.a $(PRINTF)/libftprintf.a -ldl -lglfw -pthread -lm
SRCS	:= $(addprefix $(SRCS_PATH),\
			client.c \
			server.c )

# SRCS_BONUS	:= $(addprefix $(SRCS_PATH_BONUS),\
)

OBJS	:= ${SRCS:%.c=%.o}

# OBJS_BONUS	:= ${SRCS_BONUS:%.c=%.o}

all: libmlx libft printf $(NAME)

libft:
	$(MAKE) -C ${LIBFT} all

printf:
	$(MAKE) -C ${PRINTF} all

%.o: %.c
	$(CC) $(HEADERS) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	printf "$(YELLOW)Compiling...$(RESET)\n"
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)
	printf "$(GREEN)Done!\n $(RESET)"

clean:
	rm -rf $(OBJS)
	# rm -rf $(OBJS_BONUS) // APAGAR SE NAO TIVER BONUS

fclean: clean
	rm -rf $(NAME)
	# rm -rf $(NAME_BONUS) // APAGAR SE NAO TIVER BONUS

re: fclean all

# bonus:
# 	$(MAKE) WITH_BONUS=TRUE

.PHONY: all, clean, fclean, re, libmlx, libft, printf, bonus
