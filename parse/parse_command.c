#include "parse.h"

char    **cut_line(char *line);
char    *cut_separator(char *line, int *i);

int		parse_command(char *line, char **envp)
{
	char **tab;
	tab = cut_line(line);
	tab = clean_tab_cmd(tab);
	ft_print_args(tab);
	ft_free_args(tab);
	return (0);
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
