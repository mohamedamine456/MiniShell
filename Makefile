PARSE_SRC = parse/parse_command.c

SRC = $(PARSE_SRC)

LIB_NAME = minishell.a
NAME = Minishell
MAIN = minishell.c

PARSE_OBJSRC = parse_command.o

OBJSRC = $(PARSE_OBJSRC)

all: $(NAME)
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(LIB_NAME) $(OBJSRC)
	ranlib $(LIB_NAME)
	gcc -g -Wall -Wextra -Werror $(MAIN) $(LIB_NAME) -o $(NAME)

clean:
	rm -f $(OBJSRC)

fclean:
	rm -f $(LIB_NAME)

re: fclean all

sanitize:
	gcc -Wall -Wextra -Werror -fsanitize=address -c $(SRC)
	ar rc $(LIB_NAME) $(OBJSRC)
	ranlib $(LIB_NAME)
	gcc -g -Wall -Wextra -Werror -fsanitize=address $(MAIN) $(LIB_NAME) -o $(NAME)

noflags:
	gcc -c -g $(SRC)
	ar rc $(LIB_NAME) $(OBJSRC)
	ranlib $(LIB_NAME)
	gcc -g $(MAIN) $(LIB_NAME) -o $(NAME)
