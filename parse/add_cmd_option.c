/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd_option.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 14:08:40 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/03 14:10:49 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	add_cmd_options(char **old_option, char *new)
{
	if (*old_option == NULL)
		*old_option = ft_strdup("");
	if (new != NULL)
		*old_option = ft_strjoin(*old_option, ft_strdup(new + 1));
}
