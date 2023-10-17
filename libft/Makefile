CC = cc
AR = ar rc
FLAGS = -Wall -Wextra -Werror
SRCS = $(addprefix srcs/, )
OBJS = $(SRCS:.c=.o)
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS)
	ar $^ -o $@
srcs/%.o: srcs/%.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)

fclean: clean

re: fclean all

.PHONY = clean fclean all
