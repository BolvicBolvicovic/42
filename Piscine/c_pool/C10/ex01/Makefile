CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILE = ft_cat.c
OBJ = $(FILE:.c=.o)
EXEC = ft_cat

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) $< -o $@

$(OBJ) : $(FILE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all

.PHONY: clean fclean re