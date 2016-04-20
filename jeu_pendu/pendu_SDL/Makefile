NAME = PENDU
SRC  = main.c \
	   game.c\
	   wordMystery.c
OBJ  = main.o \
	   game.o\
	   wordMystery.o
CC	 = gcc
FLAG = -c -Wall -Werror -Wextra -pedantic -ansi -g
CFLAG= $$(sdl-config --cflags --libs)
LIBS = -lSDL -lSDL_image -lSDL_ttf

#l'option -c permet de ne pas linker lors de la compilation

all : $(NAME) clean

$(NAME): main.o
	$(CC) $(CFLAG) $(OBJ) -o $(NAME) $(LIBS)

main.o:
	$(CC) $(CFLAG) $(FLAG) $(SRC)

clean :
	rm -f *.o *.h.gch
#% siginifie tous les .o
fclean : clean
	rm -f $(NAME)

re: fclean all
