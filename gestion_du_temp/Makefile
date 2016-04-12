NAME = time
SRC = timer.c
OBJ = timer.o
CFLAG = -Werror -Wextra -Wall
SDLFLAG = $$(sdl-config --libs --cflags)
FLAGIMG = -lSDL_image -lSDL

all: $(NAME) clean

$(NAME): $(OBJ)
	gcc $(SDLFLAG) $(CFLAG) $(OBJ) -o $(NAME) $(FLAGIMG)
$(OBJ):
	gcc $(SDLFLAG) $(CFLAG) -c -g $(SRC) $(FLAGIMG)
clean:
	rm -f *.o
fclean: clean
	rm -f $(NAME)
re: fclean all
