NAME	= ex03
CC	= c++ -Wall -Wextra -Werror -std=c++11
FILES	= $(addprefix src/, *.cpp)

all	: ${NAME}

${NAME}	: ${FILES}
	@${CC} ${FILES} -o $@

clean	:
	@rm -f ${NAME}

fclean	: clean

re	: clean all

.PHONY	: clean re
