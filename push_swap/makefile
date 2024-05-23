# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aoshimiz <aoshimiz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2004/10/10 12:07:37 by aoshimiz          #+#    #+#              #
#    Updated: 2024/05/23 18:12:39 by aoshimiz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft/libft.a
LIBFT_DIR = libft

NAME = push_swap

# ソースファイル
SRC = main.c move.c sort.c push_swap_utils1.c push_swap_utils2.c
OBJ = $(SRC:.c=.o)

# 最初に実行されるターゲット
all: $(NAME)

# push_swap 実行ファイルのビルド
$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) -L$(LIBFT_DIR) -lft

# libft.a のビルド
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# オブジェクトファイルの生成規則
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# ソースファイルとヘッダーの依存関係
main.o: main.c push_swap.h $(LIBFT)
move.o: move.c push_swap.h $(LIBFT)
sort.o: sort.c push_swap.h $(LIBFT)
push_swap_utils1.o: push_swap_utils1.c push_swap.h $(LIBFT)
push_swap_utils2.o: push_swap_utils2.c push_swap.h $(LIBFT)

# 不要ファイルの削除
clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

# 全ての生成ファイルの削除
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# 全てを一から再ビルド
re: fclean all

# 特別なターゲットを指定
.PHONY: all clean fclean re
