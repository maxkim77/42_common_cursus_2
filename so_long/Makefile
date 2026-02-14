NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
		game_init.c \
		map_load.c \
		map_load_utils.c \
		map_utils.c \
		img.c \
		key.c \
		player.c \
		exit.c \
		map.c \
		path.c \
		error_free.c \
		Libft/ft_memcmp.c \
		Libft/ft_strrchr.c \
		Libft/ft_strlenn.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c \
		ft_printf/ft_printf.c \
		ft_printf/ft_printf_detail.c

OBJS = $(SRCS:.c=.o)

MLX_DIR = minilibx-linux

# ===== Linux (42경산) =====
MLX_LIB = -L$(MLX_DIR) -lmlx
SYS_LIBS = -lXext -lX11 -lm

# ===== macOS =====
# MLX_DIR = minilibx-linux
# MLX_LIB = -L$(MLX_DIR) -lmlx
# SYS_LIBS = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(SYS_LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) clean -C $(MLX_DIR)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
