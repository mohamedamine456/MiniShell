#include "terminal.h"

int check_line_errors(char *line)
{
int i;
t_escapes escp;

i = 0;
escp = (t_escapes){0, 0, 0};
while (line != NULL && line[i] != '\0')
{
escp = check_escapes(escp, line[i]);
i++;
}
if (escp.b_s == 1 || escp.s_q %s != 0 || escp.d_q % 2 != 0)
    return (-1);
return (0);
}
