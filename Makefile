# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 18:04:32 by mlachheb          #+#    #+#              #
#    Updated: 2021/04/01 15:08:03 by eel-orch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = minishell.a
LIBFT = libft/libft.a

NAME = Minishell
MAIN = minishell.c

PARSE_SRC = parse/check_options.c parse/clean_tab_cmd.c parse/cmd_add_back.c\
			parse/cmd_functions_test.c parse/cmd_last.c\
			parse/free_cmd.c parse/new_cmd.c parse/parse_command.c\
			parse/print_cmd.c parse/replace_tab_env.c parse/replace_functions.c\
			parse/fill_command.c

GNL_SRC = get_next_line/get_next_line.c
SRC = $(PARSE_SRC) $(GNL_SRC)

PARSE_OBJSRC = parse_command.o cmd_add_back.o check_options.o cmd_functions_test.o\
			   cmd_last.o  free_cmd.o new_cmd.o print_cmd.o\
			   replace_tab_env.o clean_tab_cmd.o replace_functions.o fill_command.o\

GNL_OBJSRC = get_next_line.o
OBJSRC = $(PARSE_OBJSRC) $(GNL_OBJSRC)

all: $(NAME)

$(NAME):
	make fclean -C libft/
	make -C libft/
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(LIB_NAME) $(OBJSRC)
	ranlib $(LIB_NAME)
	gcc -g -Wall -Wextra -Werror $(MAIN) $(LIB_NAME) $(LIBFT) -o $(NAME)

clean:
	make clean -C libft/
	rm -f $(OBJSRC)

fclean:
	make fclean -C libft/
	rm -f $(LIB_NAME)

re: fclean all

sanitize:
	make fclean -C libft/
	make -C libft/
	gcc -Wall -Wextra -Werror -fsanitize=address -c $(SRC)
	ar rc $(LIB_NAME) $(OBJSRC)
	ranlib $(LIB_NAME)
	gcc -g -Wall -Wextra -Werror -fsanitize=address $(MAIN) $(LIB_NAME) $(LIBFT) -o $(NAME)

noflags:
	make fclean -C libft/
	make -C libft/
	gcc -c -g $(SRC)
	ar rc $(LIB_NAME) $(OBJSRC)
	ranlib $(LIB_NAME)
	gcc -g $(MAIN) $(LIB_NAME) $(LIBFT) -o $(NAME)
