#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (min >= max)
		return (0);
	else
		size = max - min;
	*range = malloc(size * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = -1;
	while (++i < size)
		(*range)[i] = min + i;
	return (size);
}
