NAME = ttf
SRC = essai.c
OBJ = essai.o
CFLAG = -Werror -Wextra -Wall
SDLFLAG = $$(sdl-config --libs --cflags)
FLAGIMG = -lSDL_image -lSDL -lSDL_ttf

all: $(NAME) clean

$(NAME): $(OBJ)
	gcc $(SDLFLAG) $(CFLAG) $(OBJ) -o $(NAME) $(FLAGIMG)
$(OBJ):
	gcc $(SDLFLAG) $(CFLAG) -c -g $(SRC)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
