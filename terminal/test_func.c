# include "terminal.h"

int main()
{
	char	*line;
	char	*tmp;
	struct termios orig;
	struct termios term;
	t_flags fl;

	tmp = malloc(2);
	line = ft_strdup("");
	fl = (t_flags){0, 0, 0};
	if (tcgetattr(0, &term) == -1)
		return (-1);
	else
	{
		orig = term;
		term.c_lflag &= ~(ICANON | ECHO);
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		if (tcsetattr(0, TCSAFLUSH, &term) == -1)
			return (-1);
		else
		{
			write(1, "Minishell $> ", 13);
			while (TRUE)
			{
				if (read(0, tmp, 1) > 0)
				{
					tmp[1] = '\0';
					if (tmp[0] == '\n')
						break ;
					else if (tmp[0] == 4)
					{
						if (!ft_strcmp(line, ""))
							exit(0);
					}
					else if (tmp[0] == 127)
					{
						int		len;
						char	*clear;
						char	*beg_line;

						len = ft_strlen(line);
						beg_line = tgetstr("cr", 0);
						clear = tgetstr("dl", 0);
						tputs(beg_line, 1, ft_putchar);
						if (len > 0)
							line[len - 1] = '\0';
						tputs(clear, 1, ft_putchar);
					}
					else
					{
						write(1, tmp, 1);
						line = ft_strjoin(line, tmp);
					}
				}
			}
			free(tmp);
			write(1, line, ft_strlen(line));
			return (0);
		}
	}
}
