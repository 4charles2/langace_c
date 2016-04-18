NAME = PENDU
SRC = main.c
OBJ = main.o
CFLAG = $(sdl-config --cflags --libs)
SFLAC = -lSDL -lSDL_ttf -lSDL_image

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAG) $(OBJ) -o $(NAME) $(SFLAC)
$(OBJ):
	gcc -c $(CFLAG) -g $(SRC) $(SFLAC)
clean:
	rm -f *.o *.gch
fclean: clean
	rm -f PENDU
re: fclean all
