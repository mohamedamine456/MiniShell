/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:22:42 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/28 16:09:59 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	isvalid_var(char *str)
{
	int i;

	if (ft_isalpha(str[0]) == 0 && str[0] != '_')
		return (-1);
	i = 1;
	while (str[i] != '\0' && str[i] != '=')
	{
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
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

void	ft_print(char *var, int is_equal)
{
	int j;

	j = 0;
	while (var[j] != '\0')
	{
		if (var[j] == '=')
			printf("=%c", 34);	
		else
			printf("%c", var[j]);
		if (var[j + 1] == '\0' && is_equal != -1)
			printf("%c", 34);
		j++;
	}
	printf("\n");
}

void	print_vars(char **vars)
{
	int i;
	int j;
	int index;
	int is_equal;

	i = 0;
	index = 0;
	while (vars[i])
	{
		if (ft_strcmp(vars[i], "export") == 0)
			i++;
		else
		{
			j = 0;
			is_equal = ft_strstri((const char *)vars[i], "=");
			printf("declare -x ");
			ft_print(vars[i], is_equal);
			i++;
		}
	}
}



void	ft_export(t_builtin_vars var, int *retv)
{
	char	**tmp;
	int		is_added;
	int		i;

	i = 0;
	*retv = 0;
	if (var.args[1] == NULL)
		sort_and_print(*(var.envp), retv);
	else
	{
		while (var.args[i] != NULL)
		{
			is_added = add_env(var, retv, i);
			if (is_added != 0)
				ft_export_errors(var.args[i], retv);			
			i++;
		}
	}
}

