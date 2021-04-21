/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 16:56:00 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/21 16:56:19 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*trim_replace(char *str, char **envp, int retv)
{
	int			i;
	t_escapes	escp;
	char		*tmp;

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
				str = replace_return(str, &i, retv);
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

char	*replace_return(char *str, int *i, int retv)
{
	char	*new_str;
	char	*tmp;

	new_str = ft_substr(str, 0, *i);
	if (retv == 1)
		tmp = ft_strdup("1");
	else
		tmp = ft_strdup("0");
	new_str = ft_strjoin(new_str, tmp);
	free(tmp);
	tmp = ft_substr(str, *i + 2, ft_strlen(str) - *i - 2);
	new_str = ft_strjoin(new_str, tmp);
	free(tmp);
	free(str);
	return (new_str);
}
