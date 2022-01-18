#include <unistd.h>

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int ac, char **ss)
{
	if (ac)
	{
		write(1, ss[0], ft_strlen(ss[0]));
		write(1, "\n", 1);
	}
}
