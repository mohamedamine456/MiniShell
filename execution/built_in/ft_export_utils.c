/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 14:56:34 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 15:19:13 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void ft_export_errors(char *identifier, int *retv)
{
	write(2, "minishell: export ", ft_strlen("minishell: export "));
	write(2, identifier, ft_strlen(identifier));
	write(2, ": not a valid identifier\n", ft_strlen(": not a valid identifier") + 1);
	*retv = -1;
}

void sort_and_print(char **env, int *retv)
{
	char **tmp;

	tmp = ft_tabdup(env);
	sort_strings(tmp);
	print_vars(tmp);
	ft_free_args(tmp);
	*retv = 0;
}

int add_env(t_builtin_vars var, int *retv, int i)
{
	int		env_index;
	char	**tmp;

	if (isvalid_var(var.args[i]) == 0)
	{
		env_index = is_duplicated_var(*(var.envp), var.args[i]);
		if (env_index != -1)
		{
			free((*(var.envp))[env_index]);
			(*(var.envp))[env_index] = ft_strdup(var.args[i]);
		}
		else
		{
			tmp = *(var.envp);
			*(var.envp) = ft_jointabstr(*(var.envp), var.args[i]);
			ft_free_args(tmp);
		}
		if (*retv != -1)
			*retv = 0;
		return (0);
	}
	return (-1);
}
