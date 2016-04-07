NAME = evenement
SRC = $(NAME).c
OBJ = $(NAME).o

GTK_FLAG = $$(pkg-config --cflags --libs gtk+-2.0)

CFLAG = -Wall -Werror -Wextra -ansi

all : $(NAME)

$(NAME): $(OBJ)
	gcc $(OBJ) $(GTK_FLAG) -o $(NAME)

$(OBJ):
	gcc -c $(SRC) $(GTK_FLAG)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
