/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:37:26 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/16 13:40:23 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include "libft/libft.h"
#include <fcntl.h>

int main()
{
	char *error_msg;
	char *path = "/dfdsfsfd/dfdfd";
	char **args = ft_split("dfdfd", 32);
	execve(path, args, NULL);
	error_msg = strerror(errno);
	write(2, error_msg, ft_strlen(error_msg));
	return (0);
}
