NAME	= ex00
CC	= c++ -Wall -Wextra -Werror -std=c++98
FILES	= $(addprefix src/, main.cpp Zombie.cpp newZombie.cpp randomChump.cpp)

all	: ${NAME}

${NAME}	: ${FILES}
	@${CC} ${FILES} -o $@

clean	:
	@rm -f ${NAME}

re	: clean all

.PHONY: clean re
