/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_jointabstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:33:15 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/03 14:26:27 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

char **ft_jointabstr(char **tab, char *str)
{
    char    **tmp_tab;
    char    **new_tab;

    tmp_tab = (char **)malloc(sizeof(char *) * 2);
    tmp_tab[0] = ft_strdup(str);
    tmp_tab[1] = NULL;
    new_tab = ft_strjoin_tables(tab, tmp_tab);
    free(tmp_tab[0]);
    free(tmp_tab);
    return (new_tab);
}
