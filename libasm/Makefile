NAME	= libasm.a
CC		= nasm
AR		= ar rcs
FILES	=
FLAGS	= -f elf64
SOURCE	= $(addprefix src/, $(FILES))
OBJ		= $(SOURCE:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJ)
	$(AR) $@ $(OBJ)
clean	:
	rm -f $(NAME)

re		: clean all

.PHONY	: re clean
