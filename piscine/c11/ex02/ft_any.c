#include <stdlib.h>
int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = -1;
	while (tab[++i] != (NULL))
		if ((*f)(tab[i]) != 0)
			return (1);
	return (0);
}
