/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlachheb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 10:58:03 by mlachheb          #+#    #+#             */
/*   Updated: 2021/04/12 18:02:18 by mlachheb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "search_commands.h"

char	*command_path(char *cmd_name, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	if (cmd_name == NULL || envp == NULL)
		return (NULL);
	paths = tab_paths(envp);
	paths = ft_strjoin_args(paths, ft_strdup("/"));
	path = check_right_path(cmd_name, paths);
	ft_free_args(paths);
	return (path);
}

char	**tab_paths(char **envp)
{
	char	**tab;
	char	*paths;
	int		i;

	i = 0;
	paths = NULL;
	tab = NULL;
	if (envp == NULL)
		return (NULL);
	while (envp[i])
	{
		tab = ft_split(envp[i], '=');
		if (tab != NULL && tab[0] != NULL)
		{
			if (!ft_strcmp(tab[0], "PATH"))
			{
				paths = ft_substr(envp[i], 5, ft_strlen(envp[i]) - 4);
				ft_free_args(tab);
				break ;
			}
			ft_free_args(tab);
		}
		i++;
	}
	if (paths != NULL)
	{
		tab = ft_split(paths, ':');
		free(paths);
	}
	return (tab);
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

//int main(int argc, char **argv, char **envp)
//{
//	char	*path;
//
//	if (argv[1] != NULL)
//	{
//		path = command_path(argv[1], envp);
//		printf("%s\n", path);
//	}
//	else
//		printf("Enter a command to look for");
//	return (0);
//}
