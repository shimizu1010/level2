NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -Imlx -lmlx -framework OpenGL -framework AppKit
SRC = fractol.c fractol_utils1.c fractol_utils2.c fractol_utils3.c
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
