struct s_int_charp
{
	int		n;
	char	*cp;
};

unsigned int	power_of(unsigned int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else if (power >= 1)
		return (nb * power_of(nb, power - 1));
	else
		return (1);
}

struct s_int_charp	check_sign_sstart(char *s)
{
	struct s_int_charp	ret;

	ret.n = 1;
	while ((*s >= 9 && *s <= 13) || *s == ' ')
		s++;
	while (*s && (*(s) == '+' || *s == '-'))
	{
		if (*s == '-')
			ret.n *= -1;
		s++;
	}
	if (*s && (!('0' <= *s && *s <= '9')))
		ret.n = 0;
	ret.cp = s;
	return (ret);
}

int	atoi(char *s, int l)
{
	unsigned int	n;
	int				i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		n += (s[i] - '0') * power_of(10, l - i - 1);
		i++;
	}
	return (n);
}

int	ft_atoi(char *s)
{
	unsigned int		i;
	struct s_int_charp	sign_sstart;

	sign_sstart = check_sign_sstart(s);
	if (sign_sstart.n == 0)
		return (0);
	i = 0;
	while (sign_sstart.cp[i])
	{
		if (!('0' <= sign_sstart.cp[i] && sign_sstart.cp[i] <= '9'))
			break ;
		else
			i++;
	}
	return (sign_sstart.n * atoi(sign_sstart.cp, i));
}
