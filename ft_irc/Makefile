NAME	= ircserv
CC		= c++ -g -Wall -Wextra -Werror -std=c++98
FILES	= $(addprefix server/, main.cpp Server.cpp Client.cpp command.cpp)

all	: ${NAME}

${NAME}	: ${FILES}
	@${CC} ${FILES} -o $@

fclean	: clean

clean	:
	@rm -f ${NAME}

re	: clean all

.PHONY	: clean re
