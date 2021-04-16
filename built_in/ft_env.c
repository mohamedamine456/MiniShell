/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 08:35:02 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/16 13:27:47 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_env(t_builtin_vars var, int *retv)
{
	int		i;
	char	**envp;

	i = 0;
	envp = *(var.envp);
	if (!ft_look_path(*(var.envp)))
		ft_builtin_errors("env", 2, retv);
	else
	{
		while (envp != NULL && envp[i] != NULL)
		{
			if (ft_isenv(envp[i]))
			{
				write(1, envp[i], ft_strlen(envp[i]));
				if (envp[i + 1] != NULL)
					write(1, "\n", 1);
			}
			i++;
		}
		*retv = 0;
	}
}

//int main(int argc, char **args, char **envp)
//{
//	t_builtin_vars var;
//	int retv;
//
//	var.args = NULL;
//	var.envp = &envp;
//	var.option = NULL;
//	ft_env(var, &retv);
//}
