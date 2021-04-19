#include "terminal.h"

char	*read_line(t_history *hist)
{
	t_termios	orig;
	char		*cmd_line;

	if (!format_terminal(&orig))
	{
		write(1, "MiniShell $> ", 13);
		cmd_line = just_read(hist);
		return (cmd_line);
	}
	return (NULL);
}

char	*just_read(t_history *hist)
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
			line = add_buffer(line, tmp, &fl, hist);
		}
		else
			break ;
	}
	free(tmp);
	return (line);
}

char	*add_buffer(char *line, char *tmp, t_flags *fl, t_history *hist)
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
		hist->wr = 1;
		write(1, tmp, 1);
		line = ft_strjoin(line, tmp);
		return (line);
	}
	else
	{
		apply_flags(&line, tmp, fl, hist);
		return (line);
	}
}
