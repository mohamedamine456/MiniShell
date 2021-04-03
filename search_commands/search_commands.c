# include "search_commands.h"

char	*command_path(char *cmd_name, char **envp)
{
	char	**paths;
	char	*path;
	int		i;

	if (cmd_name == NULL || envp == NULL)
		return (NULL);
	paths = tab_paths(envp);
	return (path);
}

char	**tab_paths(char *envp)
{
	char	**tab;
	char	*paths;
	int		i;

	i = 0;
	paths = NULL;
	tab = NULL;
	if (cmd_name == NULL || envp == NULL)
		return (NULL);
	while (envp[i])
	{
		tab = ft_split(envp[i], '=');
		if (tab != NULL && tab[0] != NULL)
		{
			if (!ft_strcmp(tab[0], "PATH"))
			{
				paths = ft_substr(envp[i], 4, ft_strlen(envp[i] - 4));
				ft_free_args(tab);
				break ;
			}
			ft_free_args(tab);
		}
		i++;
	}
	if (paths != NULL)
		tab = ft_split(paths, ':');
	return (tab);
}
