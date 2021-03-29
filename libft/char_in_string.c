#include "libft.h"

/**
 * Test if a character is in the string
*/

int		char_in_string(char c, char *str)
{
	int	i;

	i= 0;
	while (str[i] != '\0')
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}