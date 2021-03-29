# include "libft.h"

/**
 * This Function Remove Additional spaces from a string
*/

char	*ft_remove_spaces(char *str)
{
	int		i;
	int		j;
	int		n_s;
	char	*tmp;
	char	*new;

	i = 0;
	j = 0;
	n_s = 0;
	new = ft_strdup("");
	while (str[i] != '\0')
	{
		if (ft_isspace(str[i]))
			i++;
		else
		{
			n_s = ft_next_space(str + i);
			tmp = ft_substr(str, i, n_s);
			new = ft_strjoin(new, tmp);
			i += n_s;
			if (str[i] != '\0')
				new = ft_strjoin(new, " ");
			free(tmp);
		}
	}
	if (new[ft_strlen(new) - 1] == ' ')
		new[ft_strlen(new) - 1] = '\0';
	free(str);
	return(new);
}
