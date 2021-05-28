#include "minishell.h"

int		open_history(void)
{
	int		fd;

	fd = open(".minishell_history", 
			O_RDWR | O_CREAT | O_APPEND, S_IWUSR | S_IRUSR);
	return (fd);
}

void	write_history(t_general_data *data, char *line)
{
	t_history	*new;

	if (ft_strcmp(line, ""))
	{
		if (data->fd != -1)
		{
			write(data->fd, line, ft_strlen(line));
			write(data->fd, "\n", 1);
		}
		new = new_hist();
		new->line_orig = ft_strdup(line);
		add_back_hist(&(data->hists), new);
		free(line);
		line = NULL;
		data->size += 1;
	}
	else
		free(line);
}

t_history	*read_hists(int fd, int *size)
{
	t_history	*hists;
	t_history	*new;
	char		*line;

	hists = NULL;
	if (fd != -1)
	{
		while (get_next_line(fd, &line) > 0)
		{
			new = new_hist();
			new->line_orig = ft_strdup(line);
			add_back_hist(&hists, new);
			free(line);
			line = NULL;
			*size += 1;
		}
		if (ft_strcmp(line, ""))
		{
			new = new_hist();
			new->line_orig = ft_strdup(line);
			add_back_hist(&hists, new);
			free(line);
			line = NULL;
			*size += 1;
		}
	}
	return (hists);
}

t_general_data init_general_data()
{
	t_general_data data;

	data.retv = 0;
	data.fd = open_history();
	data.hists = read_hists(data.fd, &(data.size));
	data.hists = last_hist(data.hists);
	data.command_line = NULL;
	return (data);
}
