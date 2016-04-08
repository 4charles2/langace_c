NAME = Sokoban
SRC = main.c \
		jeu.c\
		editeur.c\
		fichiers.c
LIB = fichier.h\
		jeu.h\
		constantes.h\
		editeur.h
OBJS = main.o\
		jeu.o\
		editeur.o\
		fichiers.o
FLAGS = -Werror -Wextra -Wall -ansi
SDLFLAGS = $$(sdl-config --cflags --libs)
CFLAGS = -lSDL -lSDL_image

all: $(NAME)

$(NAME): ojt
	gcc $(SDLFLAGS) $(OBJS) -o $(NAME) $(CFLAGS)
ojt:
	gcc $(SDLFLAGS) -c -g $(SRC) $(LIB) $(CFLAGS)
clean:
	rm -f *.o
	rm -f *.gch
mrproper: clean
	rm -fr $(NAME)
re: mrproper all
