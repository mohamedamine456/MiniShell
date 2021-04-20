/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eel-orch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 17:04:09 by eel-orch          #+#    #+#             */
/*   Updated: 2021/04/18 17:11:49 by eel-orch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t id;

	id = fork();
	if (id == 0)
		printf("this is the child\n");
	else if (id > 0)
	{
		wait();
		printf("this is parent");	
	}
}
