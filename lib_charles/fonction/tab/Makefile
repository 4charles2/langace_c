LIB= libtab.a
SRC= $(wildcard *.c)
OBJ=$(SRC:.c=.o)
CFLAGS= -c -std=c99

all: $(LIB) clean
$(LIB): $(OBJ)
	ar rc $@ $^
$(OBJ): $(SRC)
	gcc $(CFLAGS) $^
clean: $(OBJ)
	rm -rf $^
