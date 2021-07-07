/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 10:20:14 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/02 12:59:26 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int	parse_errors(char **tab_cmd)
{
	int	i;

	i = 0;
	while (tab_cmd != NULL && tab_cmd[i] != NULL)
	{
		if (tab_cmd[i][0] == '|')
		{
			if (i == 0)
				return (print_parse_errors(tab_cmd[i], ""));
			else if (tab_cmd[i + 1] != NULL && tab_cmd[i + 1][0] == '|')
				return (print_parse_errors(tab_cmd[i], tab_cmd[i + 1]));
		}
		else if (tab_cmd[i][0] == '>' || tab_cmd[i][0] == '<')
		{
			if (check_redirections(tab_cmd[i]))
				return (print_parse_errors(tab_cmd[i], ""));
			if (tab_cmd[i + 1] == NULL)
				return (print_parse_errors("newline", ""));
			else if (tab_cmd[i + 1] != NULL && (tab_cmd[i + 1][0] == '>'
				|| tab_cmd[i + 1][0] == '<' || tab_cmd[i + 1][0] == '|'))
				return (print_parse_errors(tab_cmd[i], ""));
		}
		i++;
	}
	return (0);
}

int	check_redirections(char *redir)
{
	int		i;
	char	c;

	i = 0;
	c = redir[0];
	while (redir[i] != '\0')
	{
		if (redir[i] != c)
			break ;
		i++;
	}
	if (i != ft_strlen(redir) && redir[i] != c && (c == '>' || c == '<'))
		return (1);
	else if (c == '<' && i > 2)
		return (1);
	else if (c == '>' && i > 2)
		return (1);
	return (0);
}

int	print_parse_errors(char *error, char *error_plus)
{
	write(2, "MiniShell: ", 11);
	write(2, "syntax error near unexpected token '", 36);
	write(2, error, ft_strlen(error));
	write(2, error_plus, ft_strlen(error_plus));
	write(2, "'\n", 2);
	return (1);
}
