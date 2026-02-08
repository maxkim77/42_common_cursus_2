CC      := cc
CFLAGS  := -Wall -Wextra -Werror
INCLUDES:= -I. -Ilibft

RM      := /bin/rm -f

NAME_SERVER := server
NAME_CLIENT := client

SRC_SERVER := server.c minitalk.c
SRC_CLIENT := client.c minitalk.c

OBJ_SERVER := $(SRC_SERVER:.c=.o)
OBJ_CLIENT := $(SRC_CLIENT:.c=.o)

DEPS := minitalk.h

LIBFT      := ./libft/libft.a
LIBFT_PATH := ./libft

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $@

$(NAME_CLIENT): $(OBJ_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $@

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_PATH)

clean:
	$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	$(RM) $(NAME_SERVER) $(NAME_CLIENT)
	$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
