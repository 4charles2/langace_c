LIB= libstr
SRC= ft_putchar.c \
	ft_putstr.c
OBJ=$(SRC:.c=.o)
CFLAGS= -c

all: $(LIB) clean
$(LIB): $(OBJ)
	ar rc libstr.a $^
$(OBJ): $(SRC)
	gcc $(CFLAGS) $^
clean: $(OBJ)
	rm -rf $^
