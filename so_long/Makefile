# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcornill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 20:04:03 by vcornill          #+#    #+#              #
#    Updated: 2023/11/16 13:19:15 by vcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX_DIR = MLX42
LIBFT_DIR = ft_printf/libft
FT_PRINTF_DIR = ft_printf

MLX = $(MLX_DIR)/build/libmlx42.a
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS =	-Wall -Wextra -Werror \
			-I$(MLX_DIR)/include/MLX42 \
			-I$(LIBFT_DIR) \
			-I$(FT_PRINTF_DIR)
LFLAGS =	-L$(MLX_DIR)/build \
			-L$(LIBFT_DIR) \
			-L$(FT_PRINTF_DIR) \
			-lmlx42 -lft -lftprintf -lglfw -ldl

FILES = main ft_check_map ft_utils window_handler ft_free ft_init_map ft_init_game ft_init_image ft_movement ft_collector

SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix src/, $(addsuffix .o, $(FILES)))

all: $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re

$(NAME): $(MLX) $(LIBFT) $(FT_PRINTF) $(OBJS)
	$(CC) -o $@ $(OBJS) $(LFLAGS)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
