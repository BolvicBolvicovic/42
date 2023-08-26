NAME = rush-2
SRC_DIR = ./srcs/
RM = /bin/rm -f

FUNCTS = main main_malloc main_algo triple dict error number string
OPTIONS = -I includes

FLAGS = -Wall -Wextra -Werror
CC = gcc

CFILES = $(patsubst %, $(SRC_DIR)%.c, $(FUNCTS))
OBJECTS = $(CFILES:.c=.o)

.PHONY: all $(NAME) $(OBJECTS) clean fclean re

all: $(NAME)

$(OBJECTS):
	@$(CC) $(OPTIONS) $(FLAGS) -c $(CFILES)

$(NAME): $(OBJECTS)
	@$(CC) $(OPTIONS) $(FLAGS) $(OBJECTS) -o $(NAME)

clean:
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
