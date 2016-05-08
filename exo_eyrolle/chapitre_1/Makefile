EXEC= ESSAI
SRC= boucleExo.c
OBJ= $(SRC:.c=.o)
CFLAGS= -Wall -Werror -Wextra -ansi -pedantic -c -g -std=c99

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
