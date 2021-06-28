/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rdwr_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 19:35:24 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/28 14:26:14 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_history(void)
{
	int		fd;

	fd = open(".minishell_history",
			O_RDWR | O_CREAT | O_APPEND, S_IWUSR | S_IRUSR);
	return (fd);
}

void	write_hist(t_general_data *data, char *line)
{
	if (ft_strcmp(line, ""))
	{
		if (data->fd != -1)
		{
			write(data->fd, line, ft_strlen(line));
			write(data->fd, "\n", 1);
		}
		free(data->hists->line_chngd);
		data->hists->line_chngd = NULL;
		data->hists = last_hist(data->hists);
		free(data->hists->line_orig);
		data->hists->line_orig = ft_strdup(line);
		if (data->hists->line_chngd != NULL)
		{
			free(data->hists->line_chngd);
			data->hists->line_chngd = NULL;
		}
		free(line);
		line = NULL;
	}
	else
		free(line);
}

void	fill_hist(t_history **hists, char *line)
{
	t_history	*new;

	new = new_hist();
	new->line_orig = ft_strdup(line);
	add_back_hist(hists, new);
	free(line);
}

t_history	*read_hists(int fd)
{
	t_history	*hists;
	char		*line;

	hists = NULL;
	if (fd != -1)
	{
		while (get_next_line(fd, &line) > 0)
		{
			fill_hist(&hists, line);
			line = NULL;
		}
		if (ft_strcmp(line, ""))
		{
			fill_hist(&hists, line);
			line = NULL;
		}
		else
			free(line);
	}
	return (hists);
}

t_general_data	init_general_data(void)
{
	t_general_data	data;

	data.retv = 0;
	data.fd = open_history();
	data.hists = read_hists(data.fd);
	data.hists = last_hist(data.hists);
	data.command_line = NULL;
	return (data);
}
