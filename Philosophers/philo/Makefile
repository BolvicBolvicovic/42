# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcornill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 20:04:03 by vcornill          #+#    #+#              #
#    Updated: 2024/02/26 13:31:55 by vcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo 

CC 	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -g -pthread #-fsanitize=thread
FILES	=	main check_args utils routine eat

SRCS	=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix src/, $(addsuffix .o, $(FILES)))

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(CFLAGS) -o $@ $(OBJS)

.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
