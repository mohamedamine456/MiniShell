/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tab_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:53:47 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/03 10:23:04 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	**replace_tab_env(char **tab_cmd, char **envp)
{
	int		i;

	i = 0;
	if (envp == NULL)
		return (tab_cmd);
	while (tab_cmd != NULL && tab_cmd[i] != NULL)
	{
		tab_cmd[i] = trim_replace(tab_cmd[i], envp);
		i++;
	}
	return (tab_cmd);
}

char	*trim_replace(char *str, char **envp)
{
	int			i;
	t_escapes	escp;

	i = 0;
	escp = (t_escapes){0, 0, 0};
	while (str[i] != '\0')
	{
		escp = ft_check_escapes(escp, str[i]);
		if (escp.s_q % 2 == 0 && escp.b_s == 0 && str[i] == '$')
		{
			if (ft_isalpha(str[i + 1]) || str[i + 1] == '_')
				str = replace_env(str, envp, &i);
            else if (str[i + 1] == '?')
				str = replace_return(str, &i);
			else if (ft_char_in_string(str[i + 1], "\'\"") && escp.d_q % 2 == 0)
			{
				str = ft_strjoin(ft_substr(str, 0, i),
						ft_substr(str, i + 1, ft_strlen(str) - i - 1));
				i--;
			}
		}
		if (str[i] != '\\' && escp.b_s == 1)
			escp.b_s = 0;
		i++;
	}
	return (str);
}

char	*search_env(char *str, char **envp)
{
	int		i;
	char	*new_str;
	char	**tab;

	i = 0;
	tab = NULL;
	new_str = NULL;
	if (str == NULL || envp == NULL)
		return (NULL);
	while (envp[i] != NULL)
	{
		tab = ft_split(envp[i], '=');
		if (tab != NULL && tab[0] != NULL)
		{
			if (!ft_strcmp(str, tab[0]))
			{
				new_str = ft_substr(envp[i], ft_strlen(tab[0]) + 1, ft_strlen(envp[i]) - ft_strlen(tab[0]) - 1);
				ft_free_args(tab);
				break ;
			}
			ft_free_args(tab);
		}
		i++;
	}
	free(str);
	return (new_str);
}

char	*replace_env(char *str, char **envp, int *i)
{
	int		j;
	char	*new_str;
	char	*tmp;

	j = 1;
	while (str[*i + j] != '\0')
	{
		if (!ft_isalnum(str[*i + j]) && str[*i + j] != '_')
			break ;
		j++;
	}
	new_str = ft_substr(str, 0, *i);
	tmp = ft_substr(str, *i + 1	, j - 1);
	tmp = search_env(tmp, envp);
	if (tmp == NULL)
		tmp = ft_strdup("");
	new_str = ft_strjoin(new_str, tmp);
	free(tmp);
	tmp = ft_substr(str, *i + j, ft_strlen(str) - *i - j);
	new_str = ft_strjoin(new_str, tmp);
	free(str);
	free(tmp);
	return (new_str);
}

char	*replace_return(char *str, int *i)
{
	char *tmp_part;

	return (str);
}
