# include "libft.h"

t_escapes		ft_check_escapes(t_escapes escp, char c)
{
	if (c == '\\' && escp.s_q % 2 == 0)
	{
		if (escp.b_s == 1)
			escp.b_s = 0;
		else
			escp.b_s = 1;
	}
	if (c == '\"' && escp.b_s == 0 && escp.s_q % 2 == 0)
		escp.d_q++;
	if (c == '\'' && escp.b_s == 0 && escp.d_q % 2 == 0)
		escp.s_q++;
	return (escp);
}
