NAME = pendu
SRC = main.c \
      main.h \
	  mot_mystere.c\
	  engine_game.c
CC = gcc
CFLAG = -c -Wall -Werror -Wextra -pedantic -ansi -g
#l'option -c permet de ne pas linker lors de la compilation

all : $(NAME)

$(NAME): main.o
	$(CC) main.o mot_mystere.o  engine_game.o -o $(NAME)

main.o:
	$(CC) $(CFLAG) $(SRC)

clean :
	rm -f *.o *.h.gch
#% siginifie tous les .o
fclean : clean
	rm -f $(NAME)

re: fclean all
