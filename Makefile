# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/29 18:04:32 by mlachheb          #+#    #+#              #
#    Updated: 2021/06/29 20:34:20 by eel-orch         ###   ########.fr        #
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
			parse/is_redirection.c parse/fill_command_utils.c\

TERMINAL_SRC = terminal/check_flags.c terminal/delete_char.c terminal/format_terminal.c\
			  terminal/read_line.c terminal/quit_delete.c terminal/history_functions.c\
			  terminal/signal_handler.c terminal/check_line_errors.c terminal/init_read_tools.c

BUILTINS_SRC = execution/built_in/exec_builtins.c execution/built_in/ft_cd.c execution/built_in/ft_echo.c\
			   execution/built_in/ft_env.c execution/built_in/ft_exit.c execution/built_in/ft_export.c\
			   execution/built_in/ft_pwd.c execution/built_in/ft_unset.c execution/built_in/ft_builtin_errors.c\
			   execution/built_in/isbuilt_in.c execution/built_in/sort_strings.c execution/ft_exec_nested_cmd.c\
			   execution/built_in/ft_execute.c execution/search_commands.c\
			   open_files/open_outputs.c execution/get_exit_status.c execution/here_doc.c\
			   execution/built_in/ft_export_utils.c execution/dup_pipes.c \
			   execution/execution_errors.c execution/redirect_std_in_out.c

GNL_SRC = get_next_line/get_next_line.c
SRC = $(PARSE_SRC) $(TERMINAL_SRC) $(GNL_SRC) $(BUILTINS_SRC)\
	  rdwr_history.c parse_execute.c print_cmds.c hist_functions.c

all: $(NAME)

$(NAME):
	make fclean -C libft/
	make -C libft/
	make clean -C libft/
	gcc -Wall -Wextra -Werror $(SRC) $(MAIN) $(LIBFT) -lreadline -L ~/.brew/opt/readline/lib\
		-I ~/.brew/opt/readline/include -ltermcap -o $(NAME)

clean:
	make clean -C libft/

fclean:
	make fclean -C libft/

rmexec:
	rm -rf $(NAME)

re: fclean rmexec all

sanitize:
	make fclean -C libft/
	make -C libft/
	make clean -C libft/
	gcc -fsanitize=address $(SRC) $(MAIN) $(LIBFT) -lreadline -L ~/.brew/opt/readline/lib\
		-I ~/.brew/opt/readline/include -ltermcap -o $(NAME)

noflags:
	make fclean -C libft/
	make -C libft/
	make clean -C libft/
	gcc -g $(SRC) $(MAIN) $(LIBFT) -lreadline -L ~/.brew/opt/readline/lib -I ~/.brew/opt/readline/include -ltermcap -o $(NAME)
