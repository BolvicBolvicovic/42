# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acasamit <acasamit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 20:04:03 by vcornill          #+#    #+#              #
#    Updated: 2024/02/06 16:44:07 by vcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_DIR = ft_printf/libft
FT_PRINTF_DIR = ft_printf

LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

CC = cc
CFLAGS =	-Wall -Wextra -Werror -O0 -g\
		-I$(LIBFT_DIR) \
		-I$(FT_PRINTF_DIR)
LFLAGS =	-L$(LIBFT_DIR) \
		-L$(FT_PRINTF_DIR) \
		-lft -lftprintf -lreadline
FILES = utils_cd sig_init add_missing_flags envp_var main tokenize utils utils_joinstr algo_execv join_strings update_t_f utils_envpvar utils_tokenize built_in built_in2 built_in3 export special_char command_main command_utils exec_command main_loop free

SRCS = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS = $(addprefix src/, $(addsuffix .o, $(FILES)))

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $@ $(OBJS) $(LFLAGS)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)
	@make fclean -C $(FT_PRINTF_DIR)
	@make fclean -C $(LIBFT_DIR)

fclean : clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
