NAME	= Harl2.0
CC	= c++ -Wall -Wextra -Werror -std=c++98
FILES	= $(addprefix src/, main.cpp Harl.cpp)

all	: $(NAME)

$(NAME)	: $(FILES)
	@$(CC) $(FILES) -o $@

clean	:
	@rm -rf $(NAME)

re	: clean all

.PHONY	: re clean
