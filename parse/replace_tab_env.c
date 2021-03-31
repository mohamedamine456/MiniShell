/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tab_env.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:27:36 by mlachheb          #+#    #+#             */
/*   Updated: 2021/03/31 09:48:19 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

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

	char *(*func[])(char *, char **, int *) = {rep_spec, rep_alpha, rep_digit};
	i = 0;
	escp = (t_escapes){0, 0, 0};
	while (str[i] != '\0')
	{
		escp = ft_check_escapes(escp, str[i]);
		if (escp.s_q % 2 == 0 && escp.b_s == 0 && str[i] == '$')
		{
			if (ft_isalnum(str[i + 1]) || ft_char_in_string(str[i + 1], DLR_SPECIALS))
				str = func[ft_char_to_func(str[i + 1])](str, envp, &i);
			else if (ft_char_in_string(str[i + 1], "\'\"") && escp.d_q % 2 == 0)
			{
				str = ft_strjoin(ft_substr(str, 0, i),
						ft_substr(str, i + 1, ft_strlen(str) - i - 1));
				i--;
			}
		}
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
