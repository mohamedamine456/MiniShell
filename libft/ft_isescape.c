# include "libft.h"

int		ft_isescape(char c)
{
	if (c =='\'' || c == '\"' || c == '\\')
		return (1);
	return (0);
}
