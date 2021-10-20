#include "./../libft.h"


int	ft_n_of_digits(unsigned int nbr)
{
	int				i;

	i = 0;
	while (nbr > 9)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char *ft_itoa(int nbr)
{
	int		j;
	char	*str;
	unsigned int n;

	j = 0;
	if (nbr < 0)
	{
		n = nbr*-1;
		j++;
	}
	else
		n = nbr;
	j += ft_n_of_digits(n);
	str = (char *)malloc((j + 1) * sizeof(char));
	str[j] = 0;
	if (j > ft_n_of_digits(n))
		str[0] = '-';
	while (n > 9)
	{
		str[j] = n % 10 + '0';
		n /= 10;
		j--;
	}
	str[j] = n % 10 + '0';
	return (str);
}
