/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:25:45 by eel-orch          #+#    #+#             */
/*   Updated: 2021/07/01 21:29:13 by eel-orch         ###   ########.fr       */
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
	write(2, "minishell: ", ft_strlen("minishell: "));
	write(2, error_msg, ft_strlen(error_msg));
	write(2, "\n", 1);
	if (errno == 2)
		exit(127);
	else if (errno == 13 || errno == 21)
		exit(126);
	exit(EXIT_FAILURE);
}
