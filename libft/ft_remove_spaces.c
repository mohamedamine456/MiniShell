/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_spaces.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:03:08 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/29 10:28:10 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * This Function Remove Additional spaces from a string
 */

void	remove_spaces_helper(char **new, char *str, int *i)
{
	char	*tmp;
	int		n_s;

	n_s = ft_next_space(str + *i);
	tmp = ft_substr(str, *i, n_s);
	*new = ft_strjoin(*new, tmp);
	*i += n_s;
	if (str[*i] != '\0')
		*new = ft_strjoin(*new, " ");
	free(tmp);
}

char	*ft_remove_spaces(char *str)
{
	int		i;
	char	*new;

	i = 0;
	new = ft_strdup("");
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
			i++;
		else
		{
			remove_spaces_helper(&new, str, &i);
		}
	}
	if (new[ft_strlen(new) - 1] == ' ')
		new[ft_strlen(new) - 1] = '\0';
	free(str);
	return (new);
}
