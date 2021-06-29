/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 14:40:43 by mlachheb          #+#    #+#             */
/*   Updated: 2021/06/29 13:29:16 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "execution.h"

char	*command_path(char *cmd_name, char **envp)
{
	char	**paths;
	char	*path;

	if (cmd_name == NULL || envp == NULL)
		return (NULL);
	paths = tab_paths(envp);
	if (paths == NULL)
		return (NULL);
	paths = ft_strjoin_args(paths, ft_strdup("/"));
	path = check_right_path(cmd_name, paths);
	ft_free_args(paths);
	return (path);
}

char	**tab_paths(char **envp)
{
	char	**tab_path;
	char	*paths;
	int		i;

	i = 0;
	paths = NULL;
	tab_path = NULL;
	if (envp == NULL)
		return (NULL);
	while (envp[i])
	{
		tab_path = ft_split(envp[i], '=');
		if (tab_path != NULL && tab_path[0] != NULL)
		{
			if (!ft_strcmp(tab_path[0], "PATH"))
			{
				paths = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 4);
				ft_free_args(tab_path);
				tab_path = NULL;
				break ;
			}
			ft_free_args(tab_path);
			tab_path = NULL;
		}
		i++;
	}
	if (paths != NULL)
	{
		tab_path = ft_split(paths, ':');
		free(paths);
	}
	return (tab_path);
}

char	*check_right_path(char *cmd_name, char **paths)
{
	struct stat	info;
	int			ret;
	int			i;
	char		*path;

	i = 0;
	if (paths == NULL || cmd_name == NULL)
		return (NULL);
	while (paths[i] != NULL)
	{
		path = ft_strjoin(ft_strdup(paths[i]), cmd_name);
		ret = lstat(path, &info);
		if (ret == 0)
			return (path);
		free(path);
		i++;
	}
	return (NULL);
}
