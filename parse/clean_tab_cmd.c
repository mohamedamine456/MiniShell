# include "parse.h"

char		*clean_str(char *str)
{
	char		*new;
	int			i;
	int			j;
	t_escapes	escp;

	i = 0;
	j = 0;
	escp = (t_escapes){0, 0, 0};
	new = (char *)malloc(ft_strlen(str) + 1);
	if (new == NULL)
		return (NULL);		// prompt an allocation error and exit
	while (str[i] != '\0')
	{
		if (!ft_isescape(str[i]))
			new[j++] = str[i];
		else
		{
			escp = ft_check_escapes(escp, str[i]);
			if (str[i] == '\"' && (escp.b_s == 1 || escp.s_q % 2 == 1))
				new[j++] = str[i];
			else if (str[i] == '\'' && (escp.b_s == 1 || escp.d_q % 2 == 1))
				new[j++] = str[i];
			else if (str[i] == '\\' && ((escp.b_s == 0 && escp.d_q % 2 == 0) || escp.s_q % 2 == 1))
				new[j++] = str[i];
			else if (str[i] == '\\' && escp.b_s == 1 &&
					escp.d_q % 2 == 1 && !ft_char_in_string(str[i + 1], "\"\`$"))
				new[j++] = str[i];
		}
		if (str[i] != '\\' && escp.b_s == 1)
			escp.b_s = 0;
		i++;
	}
	new[j] = '\0';
	free(str);
	return (new);
}

char		**clean_tab_cmd(char **tab_cmd, char **envp)
{
	int		i;
	char	*tmp;

	i = 0;
	while (tab_cmd != NULL && tab_cmd[i] != NULL)
	{
		tab_cmd[i] = clean_str(tab_cmd[i]);
		i++;
	}
	return (tab_cmd);
}
