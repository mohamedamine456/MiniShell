SRC = ft_char_in_string.c ft_char_to_func.c ft_check_escapes.c\
	  ft_free_args.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_ispipe.c\
	  ft_isseparator.c ft_isspace.c ft_memmove.c ft_next_separator.c\
	  ft_next_space.c ft_print_args.c ft_putnbr.c ft_remove_spaces.c\
	  ft_resize_tab.c ft_size_args.c ft_split.c ft_split_white_spaces.c\
	  ft_str_in_args.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlcat.c\
	  ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_strstr.c ft_strstri.c\
	  ft_substr.c ft_isescape.c ft_is_string.c ft_isinput.c\
	  ft_isoutput.c ft_search_env.c ft_isenv.c ft_putchar.c ft_atoi.c

OBJ_SRC = ft_char_in_string.o ft_char_to_func.o ft_check_escapes.o\
		  ft_free_args.o ft_isalnum.o ft_isalpha.o ft_isdigit.o ft_ispipe.o\
		  ft_isseparator.o ft_isspace.o ft_memmove.o ft_next_separator.o\
		  ft_next_space.o ft_print_args.o ft_putnbr.o ft_remove_spaces.o\
		  ft_resize_tab.o ft_size_args.o ft_split.o ft_split_white_spaces.o\
		  ft_str_in_args.o ft_strcmp.o ft_strdup.o ft_strjoin.o ft_strlcat.o\
		  ft_strlcpy.o ft_strlen.o ft_strncmp.o ft_strstr.o ft_strstri.o\
		  ft_substr.o ft_isescape.o ft_is_string.o ft_isinput.o\
		  ft_isoutput.o ft_search_env.o ft_isenv.o ft_putchar.o ft_atoi.o

NAME = libft.a

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(NAME) $(OBJ_SRC)
	ranlib $(NAME)

clean:
	rm -f $(OBJ_SRC)

fclean:
	rm -f $(NAME)

re: fclean all
