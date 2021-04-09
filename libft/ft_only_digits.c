#include "libft.h"

int		ft_only_digits(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (!ft_char_in_string(str[i], "0123456789"))
            return (0);
        i++;
    }
    return (1);
}
