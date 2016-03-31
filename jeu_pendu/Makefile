NAME = pendu
SRC = main.c\
FLAG = -Wall -Werror -Wextra

all : $(NAME)

$(NAME):
	gcc $(SRC).o -o $(NAME)

main.o:
	gcc -c $(FLAG) $(SRC)

clean :
	rm $(SRC).o
