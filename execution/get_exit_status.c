/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/26 20:07:44 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 17:12:43 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

int	get_exit_status(int status)
{
	if (WIFEXITED(status) == true)
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status) == true)
		return (128 + WTERMSIG(status));
	return (0);
}
