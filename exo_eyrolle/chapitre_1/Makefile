EXEC= ESSAI
SRC= main.c
OBJ= $(SRC:.c=.o)
CFLAGS= -Wall -Werror -Wextra -ansi -pedantic -c -g

all: $(EXEC) clean
$(EXEC): $(OBJ)
	$(CC) $^ -o $@
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^
clean: $(OBJ)
	rm -rf $^
fclean: clean
	rm -rf $(EXEC)
re: fclean all
