#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	if (min > max)
		size = 0;
	else
	{
		size = max - min ;
		arr = malloc(size * sizeof(int));
	}
	if (size <= 0)
	{
		arr = NULL;
		return (0);
	}
	if (arr == NULL)
		return (0);
	i = -1;
	while (++i < size)
		arr[i] = min + i;
	return (arr);
}
