NAME=manip #Nom du programme � modifier
SRC=manipulation_sdl.c
OBJ=manipulation_sdl.o
SDLFLAGS=$$(sdl-config --cflags --libs)
CFLAGS= -lSDL -lSDL_image#Option d'optimisation du programme

all: $(NAME)

$(NAME): $(OBJ)
	 gcc $(SDLFLAGS) -o $(NAME) $(OBJ) $(CFLAGS)

$(OBJ):
	 gcc $(SDLFLAGS) -c $(SRC)

clean:	
	rm -fr *.o

mrproper: clean
	rm -fr $(NAME)

re: mrproper all
