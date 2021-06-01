#include "libft.h"

int     ft_number_length(long number)
{
    int len;

    len = 0;
    while (number > 9)
    {
        number /= 10;
        len++;
    }
    return (len + 1);
}

char    *ft_itoa(long number)
{
    char    *str;
    int     len;
    int     m;
    int     i;

    len = ft_number_length(number);
    str = (char *)malloc(len + 1);
    i = len - 1;
    while (number > 9)
    {
        m = number % 10;
        number /= 10;
        str[i] = m + 48;
        i--;
    }
    str[i] = number + 48;
    str[len] = '\0';
    return (str);
}
