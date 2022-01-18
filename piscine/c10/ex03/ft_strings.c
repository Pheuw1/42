#include "ft_h.h"

unsigned int	ft_strlen(unsigned char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(unsigned char *s1, unsigned char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

unsigned char	*ft_strdup(unsigned char *src)
{
	unsigned char	*copy;
	int		i;

	copy = (unsigned char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (copy == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		copy[i] = src[i];
	copy[i] = '\0';
	return (copy);
}