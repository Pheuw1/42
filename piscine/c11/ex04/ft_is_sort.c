int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	flag1;
	int	flag2;

	i = -1;
	flag2 = 1;
	flag1 = 1;
	while (++i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			flag1 = 0;
	}
	if (flag1)
		return (1);
	i = -1;
	while (++i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) < 0)
			flag2 = 0;
	}
	if (flag2)
		return (1);
	return (0);
}
