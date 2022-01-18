#include<unistd.h>
unsigned int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int c, char **ss)
{
	int	i;

	i = c;
	while (--i > 0)
	{
		write(1, ss[i], ft_strlen(ss[i]));
		write(1, "\n", 1);
	}
	return (0);
}
