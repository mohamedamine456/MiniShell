# include "parse.h"

char	**replace_tab_env(char **tab_cmd, char **envp)
{
	int		i;

	i = 0;
	while (tab_cmd != NULL && tab_cmd[i] != NULL)
	{
		tab_cmd[i] = replace_str(tab_cmd[i], envp);
		i++;
	}
	return (tab_cmd);
}

char	*replace_str(char *str, char **envp)
{
	char	*new_str;

	if (str == NULL || envp == NULL)
		return (NULL);
	new_str = trim_replace(str, envp);
	free(str);
	return (new_str);
}

char	*trim_replace(char *str, char **envp)
{
	int			i;
	t_escapes	escp;

	char		*(*func[])(char *, int *) = {special_char, alpha_char, digit_char};

	i = 0;
	escp = (t_escapes){0, 0, 0};
	while (str[i] != '\0')
	{
		escp = ft_check_escapes(escp, str[i]);
		if (escp.s_q % 2 == 0 && escp.b_s == 0 && str[i] == '$')
		{
			if (ft_isalnum(str[i+ 1]) || ft_char_in_string(str[i + 1], DLR_SPECIALS))
				str = func[ft_char_to_func(str[i + 1])](str, &i);
			else if (ft_char_in_string(str[i + 1], "\'\"") && escp.d_q % 2 == 0)
			{
				str = ft_strjoin(ft_substr(str, 0, i), ft_substr(str, i + 1, ft_strlen(str) - i - 1));
				i--;
			}
		}
		i++;
	}
	return (str);
}
