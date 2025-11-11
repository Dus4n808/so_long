# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 15:17:50 by dufama            #+#    #+#              #
#    Updated: 2025/11/11 09:21:18 by dufama           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c \
		src/map_read.c \
		src/map_check_shape.c \
		src/map_check_content.c \
		src/so_long_utils.c \
		src/init_game.c \
		src/get_info.c \
		src/move.c \

OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -I ./include -I ./mlx
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	MLX_DIR = ./mlx_linux
	MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S), Darwin)
	MLX_DIR = ./mlx
	MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit
endif

CFLAGS += -I $(MLX_DIR)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compilation pour $(UNAME_S)"
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(MAKE) -s -C $(MLX_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean
	@$(MAKE) -s -C $(MLX_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

leaks:
	valgrind --leak-check=full ./$(NAME)

test: all
	./$(NAME)

.PHONY: all clean fclean re
