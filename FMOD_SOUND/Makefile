NAME = Viseur
SRC = initFMOD.c
OBJ = initFMOD.o
FLAGS = -Werror -Wall -Wextra -pedantic -ansi
CFLAGS= $$(sdl-config --cflags --libs)
LIBDIR= -L/usr/include/fmodex
FMOD= -lfmod
LIB = -lSDL -lSDL_image -lfmodex

all: $(NAME) clean

$(NAME): $(OBJ)
	gcc $(LIBDIR) $(CFLAGS) -o $(NAME) -g $(OBJ) $(LIB)
$(OBJ):
	gcc $(LIBDIR) $(CFLGS) -c $(SRC) $(LIB)
clean:
	rm -f *.o
mrproper: clean
	rm -f $(NAME)
re: mrproper all
