NAME	= ex01
CC	= c++ -Wall -Wextra -Werror -std=c++98
FILES	= $(addprefix src/, Brain.cpp Animal.cpp Dog.cpp Cat.cpp main.cpp)

all	: ${NAME}

${NAME}	: ${FILES}
	@${CC} ${FILES} -o $@

clean	:
	@rm -f ${NAME}

fclean	: clean

re	: clean all

.PHONY	: clean re
