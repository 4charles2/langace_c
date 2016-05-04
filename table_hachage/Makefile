EXEC=HACH
CC=gcc
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CFLAGS= -c -g -Wall -Werror -Wextra -pedantic -ansi
LDFLAGS= 

all: $(EXEC) clean

$(EXEC): $(OBJ)
	$(CC) $^ -o $@
$(OJB): $(SRC)
	$(CC) $(CFLAGS) $^

clean: $(OBJ)
	rm -rf $^
fclean: clean
	rm -rf $(EXEC)
re: fclean all
