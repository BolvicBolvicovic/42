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

SERVER = server
CLIENT = client

LIBFT_DIR = ft_printf/libft
FT_PRINTF_DIR = ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS =	-Wall -Wextra -Werror \
		-I$(LIBFT_DIR) \
		-I$(FT_PRINTF_DIR)
LFLAGS =	-L$(LIBFT_DIR) \
		-L$(FT_PRINTF_DIR) \
		-lft -lftprintf
FILES_C = main_client error 

SRCS_C = $(addprefix src/, $(addsuffix .c, $(FILES_C)))
OBJS_C = $(addprefix src/, $(addsuffix .o, $(FILES_C)))

FILES_S = main_server error

SRCS_S = $(addprefix src/, $(addsuffix .c, $(FILES_S)))
OBJS_S = $(addprefix src/, $(addsuffix .o, $(FILES_S)))

all: $(LIBFT) $(FT_PRINTF) $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_S)
	@$(CC) -o $@ $(OBJS_S) $(LFLAGS)

$(CLIENT): $(OBJS_C)
	@$(CC) -o $@ $(OBJS_C) $(LFLAGS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS_C)
	@rm -rf $(OBJS_S)
	@make fclean -C $(FT_PRINTF_DIR)

fclean : clean
	@rm -rf $(CLIENT)
	@rm -rf $(SERVER)

re: fclean all

.PHONY: all clean fclean re
