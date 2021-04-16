/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:01:30 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/16 10:33:50 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_cd(t_builtin_vars var, int *retv)
{
	char	*dest_path;

	if (var.args != NULL && var.args[0] != NULL)
		dest_path = ft_strdup(var.args[0]);
	else
		dest_path = search_env("HOME", *(var.envp));
	if (dest_path != NULL)
	{
		if (chdir(dest_path) != 0)
			ft_builtin_errors(strerror(errno), retv);
		else
		{
			*retv = 0;
			//change_pwdenv();
		}
	}
	else
		ft_builtin_error("MiniShell: cd: HOME not set");
}
