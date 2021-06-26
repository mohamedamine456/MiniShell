# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 18:04:32 by mlachheb          #+#    #+#              #
#    Updated: 2021/06/26 15:26:55 by mlachheb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB_NAME = minishell.a
LIBFT = libft/libft.a

NAME = minishell
MAIN = minishell.c

PARSE_SRC = parse/check_options.c parse/clean_tab_cmd.c\
			parse/add_cmd_option.c parse/parse_command.c\
			parse/replace_env.c parse/fill_command.c\
			parse/structs_functions/cmd_functions.c \
			parse/structs_functions/input_functions.c\
			parse/parse_errors.c parse/replace_tab_env.c\
			parse/is_redirection.c\

TERMINAL_SRC = terminal/check_flags.c terminal/delete_char.c terminal/format_terminal.c\
			  terminal/read_line.c terminal/quit_delete.c terminal/history_functions.c\
			  terminal/signal_handler.c terminal/check_line_errors.c terminal/init_read_tools.c

BUILTINS_SRC = execution/built_in/exec_builtins.c execution/built_in/ft_cd.c execution/built_in/ft_echo.c\
			   execution/built_in/ft_env.c execution/built_in/ft_exit.c execution/built_in/ft_export.c\
			   execution/built_in/ft_pwd.c execution/built_in/ft_unset.c execution/built_in/ft_builtin_errors.c\
			   execution/built_in/isbuilt_in.c execution/built_in/sort_strings.c execution/ft_exec_nested_cmd.c\
			   execution/built_in/ft_execute.c fork_commands/search_commands.c\
			   open_files/open_outputs.c
		

GNL_SRC = get_next_line/get_next_line.c
SRC = $(PARSE_SRC) $(TERMINAL_SRC) $(GNL_SRC) $(BUILTINS_SRC)\
	  rdwr_history.c parse_execute.c print_cmds.c hist_functions.c



PARSE_OBJSRC =	parse_command.o check_options.o add_cmd_option.o\
				replace_env.o clean_tab_cmd.o fill_command.o\
				cmd_functions.o input_functions.o \
				parse_errors.o replace_tab_env.o is_redirection.o

TERMINAL_OBJSRC = check_flags.o delete_char.o format_terminal.o\
				  read_line.o quit_delete.o history_functions.o\
				  signal_handler.o check_line_errors.o init_read_tools.o

BUILTINS_OBJSRC = exec_builtins.o ft_cd.o ft_echo.o ft_env.o ft_exit.o ft_export.o\
			   ft_pwd.o ft_unset.o isbuilt_in.o sort_strings.o ft_builtin_errors.o\
			   ft_execute.o ft_exec_nested_cmd.o search_commands.o \
			   open_outputs.o

GNL_OBJSRC = get_next_line.o
OBJSRC = $(PARSE_OBJSRC)  $(TERMINAL_OBJSRC) $(GNL_OBJSRC) $(BUILTINS_OBJSRC)\
		 rdwr_history.o parse_execute.o print_cmds.o hist_functions.o


all: $(NAME)

$(NAME):
	make fclean -C libft/
	make -C libft/
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar rc $(LIB_NAME) $(OBJSRC)
	ranlib $(LIB_NAME)
	gcc -g -Wall -Wextra -Werror $(MAIN) $(LIB_NAME) $(LIBFT) -ltermcap -o $(NAME)

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
	gcc -fsanitize=address -c $(SRC)
	ar rc $(LIB_NAME) $(OBJSRC)
	ranlib $(LIB_NAME)
	gcc -fsanitize=address $(MAIN) $(LIB_NAME) $(LIBFT) -ltermcap -o $(NAME)

noflags:
	make fclean -C libft/
	make -C libft/
	gcc -c -g $(SRC)
	ar rc $(LIB_NAME) $(OBJSRC)
	ranlib $(LIB_NAME)
	gcc -g $(MAIN) $(LIB_NAME) $(LIBFT) -ltermcap -o $(NAME)
