#include "libft.h"

int ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\b')
		return (1);
	return (0);
}
