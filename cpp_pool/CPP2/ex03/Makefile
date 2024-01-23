NAME	= ex02
CC	= c++ -g -Wall -Wextra -Werror -std=c++98
FILES	= $(addprefix src/, main.cpp Fixed.cpp bsp.cpp Point.cpp)

all	: ${NAME}

${NAME}	: ${FILES}
	@${CC} ${FILES} -o $@

clean	:
	@rm -f ${NAME}

re	: clean all

.PHONY	: clean re
