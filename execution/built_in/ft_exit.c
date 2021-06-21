/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:33:31 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/21 17:25:31 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "built_in.h"

void	ft_exit(t_builtin_vars var, int *retv)
{
	double	number;

	number = 0;
	write(1, "exit\n", 5);
	if (ft_size_args(var.args) == 1)
		exit(0);
	else if (ft_size_args(var.args) == 2 && var.args[1] != NULL
		&& !check_exit_arg(var.args[1]))
	{
		number = ft_atoi(var.args[1]);
		//free alllllll
		exit(number);
	}
	else
		ft_exit_helper(var, retv);
	write(1, "\n", 1);
}

void	ft_exit_helper(t_builtin_vars var, int *retv)
{
	int	number;

	if (var.args[1] != NULL && check_exit_arg(var.args[1]))
	{
		number = 255;
		write(1, "MiniShell: exit: ", 17);
		write(1, var.args[1], ft_strlen(var.args[1]));
		write(1, ": numeric argument required", 27);
		exit(number);
	}
	else
	{
		number = 0;
		*retv = 1;
		write(1, "MiniShell: exit: too many arguments", 35);
	}
}

int		check_exit_arg(char *str)
{
    int		i;
	double	number;

    i = 0;
	str = ft_remove_spaces(ft_strdup(str));
	if (str[i] == '-' || str[i] == '+')
		i = 1;
    while (str[i] != '\0')
    {
        if (!ft_char_in_string(str[i], "0123456789"))
            return (1);
        i++;
    }
	number = ft_atoi(str);
	if (number > LLONG_MAX || number < LLONG_MIN)
		return (1);
    return (0);
}
