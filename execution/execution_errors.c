/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:25:45 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/29 20:30:23 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	command_not_found(char *str)
{
	write(2, "minishell: ", ft_strlen("minishell: "));
	write(2, str, ft_strlen(str));
	write(2, ": command not found\n", ft_strlen(": command not found") + 1);
	exit(127);
}

void	execve_error(void)
{
	char	*error_msg;

	error_msg = strerror(errno);
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	exit(126);
}
