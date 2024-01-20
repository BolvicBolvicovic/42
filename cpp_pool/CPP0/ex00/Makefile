NAME	= megaphone
CC	= c++ -Wall -Wextra -Werror -std=c++98
FILES	= $(addprefix src/, megaphone.cpp)

all	: ${NAME}

${NAME}	: ${FILES}
	@${CC} ${FILES} -o $@

clean	:
	@rm -f ${NAME}

re	: clean all

.PHONY: clean re
