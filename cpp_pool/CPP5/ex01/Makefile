NAME	= ex01
CC	= c++ -g -Wall -Wextra -Werror -std=c++98
FILES	= $(addprefix src/, *.cpp)

all	: ${NAME}

${NAME}	: ${FILES}
	@${CC} ${FILES} -o $@

clean	:
	@rm -f ${NAME}

fclean	: clean

re	: clean all

.PHONY	: clean re
