/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:22:42 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/05 15:34:48 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

int	isvalid_var(char *str)
{
	int i;

	if (ft_isdigit(str[0]) == 1 && str[0] != '_')
		return (-1);
	i = 1;
	while (str[i] != '\0' && str[i] != '=')
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
			while (vars[i][j] != '\0')
			{
				if (vars[i][j] == '=')
					printf("=%c", 34);	
				else
					printf("%c", vars[i][j]);
				if(vars[i][j + 1] == '\0' && is_equal != -1)
					printf("%c", 34);
				j++;
			}
			printf("\n");
			i++;
		}
	}
}

int	is_duplicated_var(char **env, char *var)
{
	char 	**table;
	char	**var_key;
	int		is_duplicated;
	int		i;

	is_duplicated = -1;
	i = 0;
	table = NULL;
	var_key = ft_split(var, '=');
	while (env[i] && is_duplicated == -1)
	{
		table = ft_split(env[i], '=');
		if (ft_strcmp(table[0], var_key[0]) == 0)
			is_duplicated = i;
		ft_free_args(table);
		i++;
	}
	ft_free_args(var_key);
	return (is_duplicated);
}

void	ft_export(t_builtin_vars var, int *retv)
{
	char	**tmp;
	int index;
	int		i;

	i = 0;
	*retv = 0;
	if (var.args[1] == NULL)
	{
		tmp = ft_tabdup(*(var.envp));
		sort_strings(tmp);
		print_vars(tmp);
		ft_free_args(tmp);
		*retv = 0;
	}
	else
	{
		while (var.args[i] != NULL)
		{
			if (isvalid_var(var.args[i]) == 0)
			{
				index = is_duplicated_var(*(var.envp), var.args[i]);
				if (index != -1)
				{
					free((*(var.envp))[index]);
					(*(var.envp))[index] = ft_strdup(var.args[i]);
				}
				else
				{
					tmp = *(var.envp);
					*(var.envp) = ft_jointabstr(*(var.envp), var.args[i]);
					ft_free_args(tmp);
				}
				if (*retv != -1)
					*retv = 0;
			}
			else
				*retv = -1;//invalide identifier
			i++;
		}
	}
}

//int main(int argc, char **argv, char **env)
//{
//	t_builtin_vars vars;
//	int retv = 0;
//	char **env_dup;
//	vars.args = (char **)malloc(sizeof(char *) * 3);
//	vars.args[0] = ft_strdup("export");
//	vars.args[1] = ft_strdup("AAA = ls -la");
//	vars.args[2] = NULL;
//	vars.option = NULL;
//	vars.envp = (char ***)malloc(sizeof(char **));
//	env_dup = ft_tabdup(env);
//	*(vars.envp) = env_dup;
//	ft_export(vars, &retv);
//
//}
