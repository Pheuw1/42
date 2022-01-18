#include "ft_tail.h"

int	check_n(char *str, char *prog_name)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr(basename(prog_name));
			write(2, ": illegal offset -- ", 20);
			while (*str)
			{
				write(2, str, 1);
				str++;
			}
			write(2, "\n", 1);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	i;

	nbr = 0;
	i = 0;
	if (*str == '-')
		i++;
	while (str[i])
	{
		nbr = nbr * 10 + str[i] - 48;
		i++;
	}
	return (nbr);
}

void	ft_stdin(int n, char *prog_name)
{
	char	c;
	int		fd;

	fd = open("temp", O_RDWR | O_CREAT | O_APPEND | O_TRUNC, S_IRWXU);
	while (read(0, &c, 1) > 0)
		write(fd, &c, 1);
	display("temp", n, prog_name);
	close(fd);
}

void	ft_tail(int i, int ac, int n, char **av)
{
	int		put_n;

	put_n = 0;
	if (check_n(av[2], av[0]))
	{
		n = ft_atoi(av[2]);
		if (ac == 3)
			ft_stdin(n, av[0]);
		while (++i < ac)
		{
			if (!check_er(av[i], av[0]))
			{
				if (ac > 4)
				{
					if (i != 3 && put_n == 1)
						put_title(av[i], 1);
					else
						put_title(av[i], 0);
				}
				display(av[i], n, av[0]);
				put_n = 1;
			}
		}
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		put_n;
	int		n;

	i = 2;
	put_n = 0;
	n = 0;
	if (ac < 3)
	{
		ft_putstr(basename(av[0]));
		write(2, ": option requires an argument -- c\n", 35);
	}
	else
		ft_tail(i, ac, n, av);
}
