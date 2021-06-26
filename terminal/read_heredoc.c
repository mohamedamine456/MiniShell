#include "terminal.h"

char	*read_heredoc(char *prompt)
{
	t_read_tools	rt;
	char			*line;

	if (!format_terminal(&(g_data.orig)))
	{
		init_read_tools(&rt);
		write(1, prompt, ft_strlen(prompt));
		line = just_read_heredoc(&rt, prompt);
		reset_terminal(&(g_data.orig));
		free(rt.tmp);
		return (line);
	}
	return (NULL);
}

char	*just_read_heredoc(t_read_tools *rt, char *prompt)
{
	char	*line;

	line = ft_strdup("");
	while (TRUE)
	{
		if (read(0, rt->tmp, 1) > 0)
		{
			rt->tmp[1] = '\0';
			if (rt->tmp[0] == '\n')
			{
				write(1, "\n", 1);
				break ;
			}
			line = add_line(rt, line, prompt);
		}
		else
			break ;
	}
	return (line);
}

char	*add_line(t_read_tools *rt, char *line, char *prompt)
{
	if (rt->tmp[0] == 4 || rt->tmp[0] == 3)
	{

	}
	if (!check_flags(rt->tmp[0], &(rt->fl)))
	{
		write(1, rt->tmp, 1);
		line = ft_strjoin(line, rt->tmp);
	}
}
