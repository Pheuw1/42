#include <stdlib.h>
int	ft_atoi_base(char *str, char *base);

unsigned int	ft_check_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (base[++i])
	{
		j = -1;
		while (base[++j])
			if ((base[i] == base[j] && j != i) || base[i] == '+'
				|| base[i] == '-' || (base[i] >= 9 && 13 >= base[i])
				|| base[i] == ' ')
				return (0);
	}
	return (i);
}

int	ft_size_in_b(int nbr, unsigned int bl)
{
	int				i;
	unsigned int	n;

	if (nbr < 0)
		n = nbr * -1;
	else
		n = nbr;
	i = 0;
	while (n >= bl)
	{
		n /= bl;
		i++;
	}
	return (i);
}

void	itoa(int nbr, char *base_to, unsigned int bl, char *dest)
{
	int				j;
	unsigned int	n;

	if (nbr < 0)
	{
		n = nbr * -1;
		j = ft_size_in_b(n, bl) + 2;
		dest[0] = '-';
	}
	else
	{
		n = nbr;
		j = ft_size_in_b(n, bl) + 1;
	}
	dest[j] = 0;
	j--;
	while (n >= bl)
	{
		dest[j] = base_to[n % bl];
		n /= bl;
		j--;
	}
	dest[j] = base_to[n % bl];
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		basef_l;
	int		baset_l;
	char	*dest;
	int		nb;

	basef_l = ft_check_base(base_from);
	baset_l = ft_check_base(base_to);
	if (basef_l < 2 || baset_l < 2)
	{
		dest = NULL;
		return (dest);
	}
	nb = ft_atoi_base(nbr, base_from);
	if (nb < 0)
		dest = (char *) malloc(ft_size_in_b(nb, baset_l) * sizeof(char) + 2);
	else
		dest = (char *) malloc(ft_size_in_b(nb, baset_l) * sizeof(char) + 1);
	itoa(nb, base_to, baset_l, dest);
	return (dest);
}
