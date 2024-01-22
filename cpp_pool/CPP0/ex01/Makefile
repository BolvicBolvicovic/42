NAME	= PhoneBook
CC	= c++ -Wall -Wextra -Werror -std=c++98
FILES	= $(addprefix src/, main.cpp Contact.cpp PhoneBook.cpp)

all	: ${NAME}

${NAME}	:
	@${CC} ${FILES} -o $@

clean	:
	@rm -f ${NAME}

re	: clean all

.PHONY: clean re
