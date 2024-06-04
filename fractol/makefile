NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Imlx -lmlx -framework OpenGL -framework AppKit
SRC = fractol.c init.c events.c main.c render.c ft_utils.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(MLX_FLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
