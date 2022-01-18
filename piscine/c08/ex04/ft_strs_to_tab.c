#include <stdlib.h>
#include "ft_stock_str.h"

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*copy;
	int		i;

	copy = malloc(ft_strlen(src) * sizeof(char) + 1);
	if (copy == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		copy[i] = src[i];
	copy[i] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*ar;
	int					i;

	ar = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (!ar)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		ar[i].size = ft_strlen(av[i]);
		ar[i].str = av[i];
		ar[i].copy = ft_strdup(av[i]);
		i++;
	}
	ar[i].str = 0;
	return (ar);
}
