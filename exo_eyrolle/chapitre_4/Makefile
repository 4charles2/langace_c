EXEC= ESSAI
SRC= table_multiplication_1a10.c
OBJ= $(SRC:.c=.o)
CFLAGS= -Wall -Werror -Wextra -ansi -pedantic -c -g -std=c99
LDFLAGS= -lm

all: $(EXEC) clean
$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $^
clean: $(OBJ)
	rm -rf $^
fclean: clean
	rm -rf $(EXEC)
re: fclean all
