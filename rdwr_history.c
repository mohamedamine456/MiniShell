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
	if (ft_strcmp(line, "") && ft_strcmp(line, data->tab_hist[data->size - 1]))
	{
		if (data->fd != -1)
		{
			write(data->fd, line, ft_strlen(line));
			write(data->fd, "\n", 1);
		}
		data->tab_hist = ft_resize_tab(data->tab_hist, line);
		data->size += 1;
		data->pos += 1;
	}
	else
		free(line);
}

t_general_data	read_history(int fd)
{
	t_general_data	data;
	char		*line;

	data.tab_hist  = NULL;
	data.size = 0;
	data.fd = fd;
	if (data.fd != -1)
	{
		while (get_next_line(data.fd, &line) > 0)
		{
			data.tab_hist = ft_resize_tab(data.tab_hist, line);
			data.size += 1;
		}
		if (ft_strcmp(line, ""))
		{
			data.tab_hist = ft_resize_tab(data.tab_hist, line);
			data.size += 1;	
		}
		else
			free(line);
		data.pos = data.size;
	}
	return (data);
}

t_general_data init_general_data()
{
	t_general_data data;

	data.retv = 0;
	data.fd = open_history();
	data = read_history(data.fd);
	//hist.command_line = NULL;
	return (data);
}
