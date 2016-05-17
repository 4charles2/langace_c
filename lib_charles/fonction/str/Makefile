LIB= libstr.a
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
CFLAGS= -c

all: $(LIB) clean
$(LIB): $(OBJ)
	ar rc $@  $^
$(OBJ): $(SRC)
	gcc $(CFLAGS) $^
clean: $(OBJ)
	rm -rf $^
fclean:
	rm -rf $(LIB)
re: fclean all
