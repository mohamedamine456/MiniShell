# include "parse.h"

char	**replace_tab_env(char **tab_cmd, char **envp)
{
	int		i;

	i = 0;
	while (tab_cmd != NULL && tab_cmd[i] != NULL)
	{
		tab_cmd[i] = replace_str(tab_cmd[i], envp);
		i++;
	}
	return (tab_cmd);
}

char	*replace_str(char *str, char **envp)
{
	char	*new_str;

	if (str == NULL || envp == NULL)
		return (NULL);
	new_str = trim_replace();
	free(str);
	return (new_str);
}

char	*trim_replace(char *str, char **envp)
{

}
