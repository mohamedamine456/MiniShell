#include "libft.h"

char	*check_h_n(const char *h, const char *n)
{
	if (*n == '\0')
		return ((char *)h);
	return (0);
}

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int found;
	int j;
	int	len;

	i = -1;
	if (*needle == '\0' || *haystack == '\0')
		return (check_h_n(haystack, needle));
	len = ft_strlen(haystack);
	while (ft_strlen((char *)needle) + (++i) <= len)
	{
		j = 0;
		if (haystack[i + j] == needle[j])
		{
			found = 1;
			while (j < ft_strlen((char *)needle) && found == 1)
			{
				if (haystack[i + j] != needle[j])
					found = 0;
				if (j == (ft_strlen((char *)needle) - 1) && found == 1)
					return ((char *)haystack + i);
				j++;
			}
		}
	}
	return (0);
}