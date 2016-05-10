EXEC= ESSAI
SRC= initialisation_dble_list_chaine.c
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
