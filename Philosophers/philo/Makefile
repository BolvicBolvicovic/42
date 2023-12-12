# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcornill <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 20:04:03 by vcornill          #+#    #+#              #
#    Updated: 2023/12/12 12:22:43 by vcornill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo 

CC 	=	cc
CFLAGS	=	-Wall -Wextra -Werror -g -pthread
FILES	=	main check_args utils routine eat

SRCS	=	$(addprefix src/, $(addsuffix .c, $(FILES)))
OBJS	=	$(addprefix src/, $(addsuffix .o, $(FILES)))

all:		$(NAME)

$(NAME):	$(OBJS)
	@$(CC) -o $@ $(OBJS) -pthread

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
