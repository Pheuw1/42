int	ft_iterative_factorial(int nb)
{
	int	n1;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	n1 = nb;
	while (--n1 > 0)
		nb *= n1;
	return (nb);
}
