NAME	= ex03
CC	= c++ -g -Wall -Wextra -Werror -std=c++98
FILES	= $(addprefix src/, *.cpp)

all	: ${NAME}

${NAME}	: ${FILES}
	@${CC} ${FILES} -o $@

clean	:
	@rm -f ${NAME}

re	: clean all

.PHONY	: clean re
