#include "parse.h"

int		parse_command(char *line, char **envp)
{
	char	**tab;
	int		ret;

	tab = cut_line(line);
    tab = replace_tab_env(tab, envp);
	tab = clean_tab_cmd(tab);
	ret = separate_command(tab);
	//ft_print_args(tab);
	ft_free_args(tab);
	return (0);
}

int		separate_command(char **tab_cmd)
{
	t_cmd	*cmd;
	char	**one_cmd;
	int		i;

	i = 0;
	one_cmd = NULL;
	while (tab_cmd != NULL && tab_cmd[i] != NULL)
	{
		if (ft_strcmp(tab_cmd[i], ";"))
			one_cmd = ft_resize_tab(one_cmd, ft_strdup(tab_cmd[i]));
		else if (one_cmd != NULL)
		{
			// fill command
			//execute command
			ft_print_args(one_cmd);
			write(1, "\n\n\n", 1);
			ft_free_args(one_cmd);
			one_cmd = NULL;
		}
		i++;
	}
	if (one_cmd != NULL)
	{
		ft_print_args(one_cmd);
		ft_free_args(one_cmd);
	}
	return (1);
}

char	**cut_line(char *line)
{
	int			i;
	int			n_s;
	char		*tmp_part;
	char		**tab;
	i = 0;
	n_s = 0;
	tab = NULL;
	if (line == NULL)
		return (NULL);
	while (line[i] != '\0')
	{
		n_s = ft_next_separator(line + i);
		tmp_part = ft_substr(line, i, n_s);
		tmp_part = ft_remove_spaces(tmp_part);
		if (ft_strcmp("", tmp_part))
			tab = ft_resize_tab(tab, ft_strdup(tmp_part));
		i += n_s;
		free(tmp_part);
		tmp_part = cut_separator(line, &i);
		if (tmp_part != NULL)
			tab = ft_resize_tab(tab, ft_strdup(tmp_part));
		free(tmp_part);
	}
	return (tab);
}

char	*cut_separator(char *line, int *i)
{
	char	*tmp_part;
	char	c;
	int		j;
	j = 0;
	tmp_part = NULL;
	if (ft_isseparator(line[*i]))
	{
		if (ft_isspace(line[*i]))
			(*i)++;
		else
		{
			if (line[*i] == '>' || line[*i] == '>')
			{
				c = line[*i];
				while (line[*i + j] == c)
					j++;
				tmp_part = ft_substr(line, *i, j);
				*i += j;
			}
			else
				tmp_part = ft_substr(line, (*i)++, 1);
		}
	}
	return (tmp_part);
}
