EXEC= EXO4
SRC= exo4.c
OBJ= $(SRC:.c=.o)
CFLAGS= -Wall -Werror -Wextra -ansi -pedantic -c -g -std=c99
LDFLAGS= -L. -lstr

all: $(EXEC) clean
$(EXEC): $(OBJ)
	$(CC) $^ $(LDFLAGS) -o $@
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^

clean: $(OBJ)
	rm -rf $^
fclean: clean
	rm -rf $(EXEC)
re: fclean all
