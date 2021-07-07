/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_tab_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:12:06 by mlachheb          #+#    #+#             */
/*   Updated: 2021/07/07 14:57:09 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char	*clean_str(char *str)
{
	char	*new;
	t_clean	cl;

	cl.i = 0;
	cl.j = 0;
	cl.escp = (t_escapes){0, 0, 0};
	new = (char *)malloc(ft_strlen(str) + 1);
	if (new == NULL)
		return (NULL);
	while (str[cl.i] != '\0')
	{
		new = clean_str_helper(str, new, &cl);
	}
	new[cl.j] = '\0';
	free(str);
	return (new);
}

char	*clean_str_helper(char *str, char *new, t_clean *cl)
{
	if (!ft_isescape(str[cl->i]))
		new[cl->j++] = str[cl->i];
	else
	{
		cl->escp = ft_check_escapes(cl->escp, str[cl->i]);
		if (str[cl->i] == '\"' && (cl->escp.b_s == 1 || cl->escp.s_q % 2 == 1))
			new[cl->j++] = str[cl->i];
		else if (str[cl->i] == '\'' && (cl->escp.b_s == 1
				|| cl->escp.d_q % 2 == 1))
			new[cl->j++] = str[cl->i];
		else if (str[cl->i] == '\\' && ((cl->escp.b_s == 0
					&& cl->escp.d_q % 2 == 0) || cl->escp.s_q % 2 == 1))
			new[cl->j++] = str[cl->i];
		else if (str[cl->i] == '\\' && cl->escp.b_s == 1
			&& cl->escp.d_q % 2 == 1
			&& !ft_char_in_string(str[cl->i + 1], "\"`$"))
			new[cl->j++] = str[cl->i];
	}
	if (str[cl->i] != '\\' && cl->escp.b_s == 1)
		cl->escp.b_s = 0;
	cl->i++;
	return (new);
}

char	**clean_tab_cmd(char **tab_cmd)
{
	int		i;

	i = 0;
	while (tab_cmd != NULL && tab_cmd[i] != NULL)
	{
		tab_cmd[i] = clean_str(tab_cmd[i]);
		i++;
	}
	return (tab_cmd);
}
