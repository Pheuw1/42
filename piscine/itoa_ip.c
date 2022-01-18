#include "./libft.h"

int	ft_n_of_digits(unsigned int nbr, int *neg)
{
	int				i;
	unsigned int	n;

	i = 0;
	if (nbr < 0)
	{
		n = nbr * -1;
		i++;
		*neg = 1;
	}
	else
		n = nbr;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nbr)
{
	int				j;
	int				i;
	char			*str;
	unsigned int	n;
	int				is_neg;

	j = ft_n_of_digits(nbr, &is_neg);
	i = 0;
	if (nbr < 0)
		n = nbr * -1;
	str = (char *)malloc((j + 1) * sizeof(char));
	if (!str)
		return (str);
	str[j] = 0;
	if (is_neg)
		str[j] = '-';
	while (i++ < j)
	{
		str[i] = n % 10 + '0';
		n /= 10;
	}
	str[j] = n % 10 + '0';
	str[j + 1] = 0;
	return (str);
}
