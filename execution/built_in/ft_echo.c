/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:31:41 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/03 19:26:28 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_echo(t_builtin_vars var, int *retv)
{
	int	i;

	i = 1;
	while (var.args != NULL && var.args[i] != NULL)
	{
		write(1, var.args[i], ft_strlen(var.args[i]));
		if (var.args[i + 1] != NULL)
			write(1, " ", 1);
        i++;
	}	
	if (errno == 0)
		*retv = 0;
	else
		*retv = 1;
	if (var.option != NULL)
		return ;
	else
		write(1, "\n", 1);
}

//int main(int argc, char *argv[], char **envp)
//{
//	t_builtin_vars vars;
//	int retv;
//
//	vars.args = ft_split("okk cc", 32);
//	vars.option = NULL;
//	vars.envp = &envp;
//	ft_echo(vars, &retv);
//}
