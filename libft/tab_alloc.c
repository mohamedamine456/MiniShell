/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 18:46:39 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 18:47:25 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**tab_alloc(char **tab)
{
	char	**new_tab;
	int		tab_len;

	tab_len = ft_strlen_tab(tab);
	new_tab = (char **)malloc(sizeof(char *) * (tab_len + 1));
	return (new_tab);
}
