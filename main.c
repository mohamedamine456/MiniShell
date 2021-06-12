/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 18:37:26 by eel-orch          #+#    #+#             */
/*   Updated: 2021/06/12 18:43:02 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

int main()
{
	char *path = "/bin/ls";
	char **args = ft_split("/bin/ls", '\0');
	execve(path, args, NULL);
	write(2, "sdf", 3);
	return (0);
}
