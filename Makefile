# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dufama <dufama@student.42lausanne.ch>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 15:17:50 by dufama            #+#    #+#              #
#    Updated: 2025/11/09 17:54:55 by dufama           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = so_long.c \
		src/map_read.c \
		src/map_check_shape.c \
		src/map_check_content.c \

OBJS = $(SRCS:.c=.o)

NAME = so_long

CC = cc
CFLAGS = -Wall -Werror -Wextra -I ./
RM = rm -f

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

all: $(NAME)

clean:
	@$(RM) $(OBJS)
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

leaks:
	valgrind --leak-check=full ./$(NAME)

test: all
	./$(NAME)

.PHONY: all clean fclean re
