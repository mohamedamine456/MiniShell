/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:22:42 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/18 15:09:14 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	isvalid_var(char *str)
{
	int i;

	if (ft_isdigit(str[0]) != 1 && str[0] != '_')
		return (-1);
	i = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '*' || str[i] == '!')
			return (-1);
		i++;
	}
	return (0);
}

char	*to_var(char *arg)
{
	int i;

	i = ft_strstri((const char *)arg, "=");
	if (i == -1)
		return (ft_strjoin(ft_strdup(arg), "=''"));
	return (arg);
}

void	ft_export(t_builtin_vars var, int *retv)
{
	char	**sorted_env;
	char	**tmp;
	int		i;

	i = 0;
	*retv = 0;
	if (var.args == NULL)
	{
		sorted_env = ft_tabdup(*(var.envp));
		sort_strings(sorted_env);
		while (sorted_env[i])
		{
			printf("%s\n", sorted_env[i]);
			i++;
		}
		*retv = 0;
		//free sorted args
	}
	else
	{
		while (var.args[i] != NULL)
		{
			if (isvalid_var(var.args[i]) == 0)
			{
				tmp = *(var.envp);
				*(var.envp) = ft_jointabstr(*(var.envp), var.args[i]);
				//free tmop
				if (*retv != -1)
					*retv = 0;
			}
			else
				*retv = -1;//invalide identifier
			i++;
		}
	}
}

int main(int argc, char *argv[], char *envp[])
{
	t_builtin_vars vars;
	int	retv;
	vars.args = NULL;
	var.envp
	*vars.envp = ft_split("aaa baa bb", 32);
	vars.option = NULL;
	//ft_export(vars, &retv);
}
