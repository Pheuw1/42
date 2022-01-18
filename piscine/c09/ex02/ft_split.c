#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	wc;

	wc = 0;
	while (*str)
	{
		while (is_sep(*str, charset) && *str)
			str++;
		if (*str)
			wc++;
		while (!is_sep(*str, charset) && *str)
			str++;
	}
	return (wc);
}

int	word_size(char *str, char *charset)
{
	int	ws;

	ws = 0;
	while (!(is_sep(*str, charset)) && *str)
	{
		ws++;
		str++;
	}
	return (ws);
}

char	*ft_strdup(char *src, int ws)
{
	char	*cpy;
	int		i;

	cpy = malloc(sizeof(char) * (ws + 1));
	if (cpy == NULL)
		return (cpy);
	i = -1;
	while (++i < ws)
		cpy[i] = src[i];
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(char *str, char *charset)
{
	char	**strs;
	int		ws;
	int		i;
	int		j;

	strs = malloc(sizeof(char *) * (word_count(str, charset) + 1));
	if (strs == NULL)
		return (strs);
	i = 0;
	j = 0;
	while (*str)
	{
		ws = 0;
		while (is_sep(*str, charset))
			str++;
		if (*str)
		{
			ws = word_size(str, charset);
			strs[i] = ft_strdup(str, ws);
			str += ws;
			i++;
		}
	}
	strs[i] = 0;
	return (strs);
}
