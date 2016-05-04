EXEC= FILE
SRC= file.c
CC= gcc
OBJ= $(SRC:.c=.o)
#FLAGS= -Wall -Wextra -Werror -ansi
DEBUG= yes

ifeq ($(DEBUG), yes)
	CFLAGS= $(FLAGS) -g
else
	CFLAGS= $(FLAGS)
endif

all: $(EXEC) clean

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
$(OBJ): $(SRC)
	$(CC) -c $< $(CFLAGS)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(EXEC)
re: fclean all
