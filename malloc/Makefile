ifeq ($(HOSTTYPE).)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

AR      = ar rcs
CFLAGS  = -Wall -Wextra -Werror -Iinc
NAME	= libft_malloc_$(HOSTTYPE).so
FILES	=
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:.c=.o)

all		: $(NAME)

$(NAME)	: $(OBJS)
	$(AR) $@ $(OBJ)

%.o		: %.c
	$(CC) $(CFLAGS) -o $@ $<

clean   :
	rm -f $(OBJS)

fclean  : clean
	rm -f $(NAME)

re      : fclean all

.PHONY  : re clean
