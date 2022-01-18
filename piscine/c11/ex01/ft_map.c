#include <stdlib.h>
int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*ret_tab;
	int	i;

	ret_tab = malloc(length * sizeof(int));
	if (!ret_tab)
		return (NULL);
	i = -1;
	while (++i < length)
		ret_tab[i] = (*f)(tab[i]);
	return (ret_tab);
}
