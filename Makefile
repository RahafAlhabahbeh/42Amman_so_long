NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra

OBJ_DIR = obj
LIBFT_DIR = ./libft
PRINTF_DIR = ./printf

SRCS = main.c check_map.c free.c prepare_map.c utils.c \
		mlx_images.c close_window.c movement_bonus.c movement2.c \
		check_borders.c
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: ft_printf libft $(NAME)

$(NAME): $(OBJS) $(LIBFT_DIR)/libft.a $(PRINTF_DIR)/libftprintf.a
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -Lmlx -lmlx -lXext -lX11 -lm -lz -o $(NAME)

libft:
	make -C $(LIBFT_DIR)

ft_printf:
	make -C $(PRINTF_DIR)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(LIBFT_DIR) -I$(PRINTF_DIR) -c $< -o $@

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

$(PRINTF_DIR)/libftprintf.a:
	@make -C $(PRINTF_DIR)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	rm -rf $(OBJ_DIR)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft ft_printf
