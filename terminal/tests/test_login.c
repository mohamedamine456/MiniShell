# include <stdio.h>
# include <stdlib.h>
# include <termios.h>
# include "../../libft/libft.h"
# define TRUE 1

char    *read_word();

int main(int argc, char **argv)
{
        struct termios info, orig;
        char    *username;
        char    *password;
        int     fd;

        write(1, "login: ", 7);
        username = read_word();

        //turn of echo
        if (tcgetattr(0, &info) == -1)
            exit(1);
        orig = info;
        info.c_lflag &= ~ECHO;
        if (tcsetattr(0, TCSANOW, &info) == -1)
            exit(1);
        write(1, "password: ", 10);
        password = read_word();
        if (tcsetattr(0, TCSANOW, &orig))
            exit(1);
        write(1, "\n", 1);
        write(1, username, ft_strlen(username));
        write(1, " password is: ", 14);
        write(1, password, ft_strlen(password));
        return (0);
}

char    *read_word()
{
        char    *buff;
        char    *tmp;

        buff = NULL;
        tmp = malloc(2);
        while (TRUE)
        {
                if (read(0, tmp, 1) > 0)
                {
                        tmp[1] = '\0';
                        if (buff == NULL)
                                buff = ft_strdup("");
                        buff = ft_strjoin(buff, tmp);
                        if (tmp[0] == '\n')
                                break ;
                }
                else
                        break;
        }
        free(tmp);
        return (buff);
}
