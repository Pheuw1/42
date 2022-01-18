#include <unistd.h>

unsigned int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s2[i] == '\0')
		return (0);
	else
		return (-s2[i]);
}

void	ft_swap_strings(char **string1, char **string2)
{
	char	*tmp;

	tmp = *string1;
	*string1 = *string2;
	*string2 = tmp;
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac - 1)
	{
		if (ft_strcmp(av[i], av[i + 1]) > 0)
		{
			ft_swap_strings(&av[i], &av[i + 1]);
			i = 0;
		}
		i++;
	}
	i = 1;
	while (i < ac)
	{
		while (*av[i])
		{
			write(1, av[i], 1);
			av[i]++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
