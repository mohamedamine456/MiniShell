/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_tab_enc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 12:00:00 by mlachheb          #+#    #+#             */
/*   Updated: 2021/05/23 12:04:38 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

char    **replace_tab_env(char **tab_cmd, char **envp, int retv)
{
    int     i;

    i = 0;
    if (*envp == NULL)
        return (tab_cmd);
    while (tab_cmd != NULL && tab_cmd[i] != NULL)
    {
        tab_cmd[i] = trim_replace(tab_cmd[i], envp, retv);
        i++;
    }
    return (tab_cmd);
}
