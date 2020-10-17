NAME = a.out
OBJ = *.o
SRC = *.c
CFLAGS = -c -Wall -Wextra -Werror
DEBUG = -O0 -g -fsanitize=address

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $@ $(DEBUG) $^

$(OBJ): $(SRC)
	gcc -c $^

.PHONY: all clean fclean re

clean:
	rm $(OBJ)

fclean: clean
	rm $(NAME)

re: fclean all