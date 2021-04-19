#include "terminal.h"

char	*read_line(void)
{
	t_termios	orig;
	char		*cmd_line;

	if (!format_terminal(&orig))
	{
		write(1, "MiniShell $> ", 13);
		cmd_line = just_read();
		return (cmd_line);
	}
	return (NULL);
}

char	*just_read(void)
{
	char	*line;
	char	*tmp;
	t_flags	fl;

	fl = (t_flags){0, 0, 0};
	line = ft_strdup("");
	tmp = malloc(2);
	while (TRUE)
	{
		if (read(0, tmp, 1) > 0)
		{
			tmp[1] = '\0';
			if (tmp[0] == '\n')
				break ;
			line = add_buffer(line, tmp, &fl);
		}
		else
			break ;
	}
	free(tmp);
	return (line);
}

char	*add_buffer(char *line, char *tmp, t_flags *fl)
{
	if (tmp[0] == 4)
	{
		if (!ft_strcmp(line, ""))
			quit_d(line);
		return (line);
	}
	else if (tmp[0] == 127)
	{
		delete_char(&line);
		return (line);
	}
	else if (!check_flags(tmp[0], fl))
	{
		write(1, tmp, 1);
		line = ft_strjoin(line, tmp);
		return (line);
	}
	else
	{
		apply_flags(&line, tmp, fl);
		return (line);
	}
}

void	print_termios(t_termios term)
{
	printf("\nc_iflag: %ld, c_oflag: %ld, c_cflag: %ld, c_lflag: %ld\n",
		term.c_iflag, term.c_oflag, term.c_cflag, term.c_lflag);
	printf("c_cc: %s, c_ispeed: %ld, c_ospeed: %ld\n",
		term.c_cc, term.c_ispeed, term.c_ospeed);
}
