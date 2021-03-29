# include "libft.h"

/**
 * This function tkes a string and return the index of the next space in the string
 * it does askip if the first characters are spaces
*/

int		next_space(char *str)
{
	int		i;
	char	*tmp;
	t_flags	fl;

	i = 0;
	tmp = NULL;
	fl = (t_flags){0, 0, 0, 0, 0, 0};
	while (str[i] != '\0')
	{
		if (str[i] == '\\')
			fl.b_s = fl.b_s == 1 ? 0 : 1;
		if (str[i] == '\"' && fl.b_s == 0 && fl.s_q % 2 == 0)
			fl.d_q++;
		if (str[i] == '\'' && fl.b_s == 0 && fl.d_q % 2 == 0)
			fl.s_q++;
		if (ft_isspace(str[i]) && fl.s_q % 2 == 0 && fl.d_q % 2 == 0 && fl.b_s == 0)
		{
			tmp = ft_substr(str, 0, i);
			if (ft_strcmp(tmp, ""))
			{
				free(tmp);
				break ;
			}
			free(tmp);
		}
		if (str[i] != '\\' && fl.b_s == 1)
			fl.b_s = 0;
		i++;
	}
	return (i);
}
