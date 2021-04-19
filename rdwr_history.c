#include "minishell.h"

int		open_history(void)
{
	int		fd;

	fd = open(".minishell_history", 
			O_RDWR | O_CREAT | O_APPEND, S_IWUSR | S_IRUSR);
	return (fd);
}

void	write_history(t_history *hist, char *line)
{
	if (ft_strcmp(line, ""))
	{
		if (hist->fd != -1)
		{
			write(hist->fd, line, ft_strlen(line));
			write(hist->fd, "\n", 1);
		}
		hist->tab_hist = ft_resize_tab(hist->tab_hist, line);
		hist->size += 1;
		hist->pos += 1;
	}
}

t_history	read_history(int fd)
{
	t_history	hist;
	char		*line;

	hist.tab_hist  = NULL;
	hist.size = 0;
	hist.fd = fd;
	if (hist.fd != -1)
	{
		while (get_next_line(hist.fd, &line) > 0)
		{
			hist.tab_hist = ft_resize_tab(hist.tab_hist, line);
			hist.size += 1;
		}
		if (ft_strcmp(line, ""))
		{
			hist.tab_hist = ft_resize_tab(hist.tab_hist, line);
			hist.size += 1;	
		}
		hist.pos = hist.size;
	}
	return (hist);
}
