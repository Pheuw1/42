int	ft_is_prime(int nb)
{
	unsigned int	i;
	unsigned int	n;

	n = nb;
	i = 5;
	if (n > 1 && n <= 3)
		return (1);
	if (!(n % 3) || !(n % 2) || n <= 1)
		return (0);
	while (i * i <= n)
	{
		if (!(n % i) || !(n % (i + 2)))
			return (0);
		i += 6;
	}
	return (1);
}
