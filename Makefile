# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 15:17:50 by dufama            #+#    #+#              #
#    Updated: 2025/12/03 12:14:55 by dufama           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c \
		src/map_read.c \
		src/map_check_shape.c \
		src/map_check_content.c \
		src/map_check_solvable.c \
		src/map_load_struct.c \
		src/map_load_graphic.c \
		src/so_long_utils.c \
		src/move.c \

OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -I ./include -I ./mlx
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a


MLX_DIR = ./mlx_linux
MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz


CFLAGS += -I $(MLX_DIR)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
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

.PHONY: all clean fclean re
