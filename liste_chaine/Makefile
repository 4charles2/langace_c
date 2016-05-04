NAME= chaine
SRC= main.c
DEBUG= yes
CC= gcc
FLAGS=-W -Wall -Werror -Wextra -pedantic -ansi -std=c99

ifeq ($(DEBUG), yes)
	CFLAGS= $(FLAGS)
else
	CFLAGS= -g $(FLAGS)
endif

all: $(NAME) clean

$(NAME): $(SRC)
	$(CC) $^ -o $@ $(CFLAGS)

clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
