NAME			= solver

CC				= c++
CFLAGS			= -Wall -Wextra -Werror -O0 -g\
					-I$(LIBFT_DIR) \
					-I$(FT_PRINTF_DIR)

FILES			= main Parser Solver

SRCS			= $(addprefix src/, $(addsuffix .cpp, $(FILES)))
OBJS			= $(addprefix src/, $(addsuffix .o, $(FILES)))

all				: $(NAME)

$(NAME)			: $(OBJS)
	@$(CC) -o $@ $(OBJS)


.cpp.o			:
	@$(CC) $(CFLAGS) -c $< -o $@

clean			:
	@rm -rf $(OBJS)

fclean			: clean
	@rm -rf $(NAME)

re				: fclean all

.PHONY			: all clean fclean re
