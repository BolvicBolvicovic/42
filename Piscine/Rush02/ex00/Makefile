# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcornill <vcornill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/27 12:08:42 by vcornill          #+#    #+#              #
#    Updated: 2023/08/27 15:32:52 by vcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror

NAME = rush-2
SRC_DIR = srcs/
RM = rm -f

FUNCTS = main.c main_alloc.c error.c checknum.c find_read.c main_algo.c dict.c string.c groupofthreedigits.c
OPTIONS = -I includes

CFILES = $(addprefix $(SRC_DIR), $(FUNCTS))
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	$(CC) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

Xre: re
	$(RM) $(OBJECTS)

.PHONY: clean fclean re Xre
