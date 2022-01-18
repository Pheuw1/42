#include <unistd.h>

unsigned int	ft_check_base(int l, char *base)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < l)
	{
		while (i < l)
		{
			if (base[i] == '-' || base[i] == '+')
				return (0);
			if ((base[i] == base[j] && i != j) || l < 2)
				return (0);
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

void	pc(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	bl;

	bl = 0;
	while (base[bl])
		bl++;
	if (bl < 1 || !ft_check_base(bl, base))
		return ;
	if (nbr < 0)
	{
		pc('-');
		n = nbr * -1;
	}
	n = nbr;
	if (n >= bl)
		ft_putnbr_base(n / bl, base);
	pc(base[n % bl]);
}
