#include "libft.h"

int		count_words(char *str)
{
	int i;
	int nb_words;
	t_escapes escp;

	i = 0;
	escp = (t_escapes){0, 0, 0};
	nb_words = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		escp = ft_check_escapes(escp, str[i]);
		if (escp.b_s == 0 && escp.d_q % 2 == 0 && escp.s_q % 2 == 0)
		{
			if (!ft_isspace(str[i]) && (ft_isspace(str[i + 1]) || str[i + 1] == '\0'))
				nb_words++;
			if (str[i + 1] == '\0')		// in case all quotes are closed
				return (nb_words);
		}
		if (str[i] != '\\' && escp.b_s == 1)
			escp.b_s = 0;
		i++;
	}
	return (nb_words + 1); // if a quote is not closed
}

int		is_word(char *str, int begin)
{
	int		i;
	t_escapes	escp;

	i = begin;
	escp = (t_escapes){0, 0, 0};
	while (str[i] != '\0')
	{
		escp = ft_check_escapes(escp, str[i]);
		if (ft_isspace(str[i + 1]) && escp.b_s == 0 && escp.d_q % 2 == 0 && escp.s_q % 2 == 0)
			break;
		if (str[i] != '\\' && escp.b_s == 1)
			escp.b_s = 0;
		i++;
	}
	return (i - begin + 1);
}

void	free_all(char **words, int i)
{
	while (i >= 0)
	{
		free(words[i]);
		i--;
	}
	free(words);
}

char	**ft_split_white_spaces(char *str)
{
	char	**words;
	int		i;
	int		word;
	int		nb_words;

	i = 0;
	word = 0;
	nb_words = count_words(str);
	words = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (str == NULL || words == NULL)
		return (NULL);
	while (str[i] != '\0' && word < nb_words)
	{
		if (ft_isspace(str[i]))
			i++;
		else
		{
			words[word] = ft_substr(str, i, is_word(str, i));
			if (words[word] == NULL)
				free_all(words, word);
			i += is_word(str, i);
			word++;
		}
	}
	words[word] = NULL;
	return (words);
}
