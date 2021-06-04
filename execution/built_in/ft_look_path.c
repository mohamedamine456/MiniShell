/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_look_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:23:44 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/04 14:55:49 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	ft_look_path(char **envp)
{
	int		i;
	char	**tmp;

	i = 0;
	while (envp != NULL && envp[i] != NULL)
	{
		tmp = ft_split(envp[i], '=');
		if (!ft_strcmp(tmp[0], "PATH"))
		{
			ft_free_args(tmp);
			return (1);
		}
		ft_free_args(tmp);
		i++;
	}
	return (0);
}

//int main(int argc, char **args, char **envp)
//{
//	int i;
//	int	retv;
//
//	i = 0;
//	if (argc > 1)
//	{
//		envp = remove_env("PATH", envp);
//		ft_env((t_builtin_vars){NULL, NULL, &envp}, &retv);
//	}
//}
