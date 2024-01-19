NAME	= humans_a.k.a.destroyers_of_worlds
CC	= c++ -g -Wall -Wextra -Werror -std=c++98
FILES	= $(addprefix src/, main.cpp Weapon.cpp HumanA.cpp HumanB.cpp)

all	: $(NAME)

$(NAME)	: $(FILES)
	@$(CC) $(FILES) -o $@

clean	:
	@rm -rf $(NAME)

re	: clean all

.PHONY	: re clean
