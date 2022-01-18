#include <stdlib.h>

struct s_atoi_base
{
	int	base_l;
	int	str_l;
	int	last_bc;
	int	sign;
};

unsigned int	power_of(unsigned int nb, int power)
{
	if (power >= 1)
		return (nb * power_of(nb, power - 1));
	else
		return (1);
}

int	ft_get_index_of_last_num_in_base(char *str, char *base)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	j = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (base[j])
		{
			if (base[j] == str[i])
				c++;
			j++;
		}
		i++;
		if (c != i)
			break ;
	}
	return (c);
}

int	ft_get_n(char *str, char *base, int base_l, int lc)
{
	int	base_pos;
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (i < lc)
	{
		base_pos = 0;
		while (base[base_pos])
		{
			if (str[i] == base[base_pos])
				n += base_pos * power_of(base_l, lc - i - 1);
			base_pos++;
		}
		i++;
	}
	return (n);
}

char	*ft_det_sign_cut_str_to_number(char *str, int *s)
{
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str)
	{
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				*s *= -1;
		}
		else
			break ;
		str++;
	}
	return (str);
}

int	ft_atoi_base(char *str, char *base)
{
	struct s_atoi_base	vals;
	int					j;

	vals.base_l = -1;
	vals.str_l = 0;
	vals.last_bc = 0;
	vals.sign = 1;
	while (base[++vals.base_l])
	{
		j = 0;
		while (base[j++])
			if ((base[vals.base_l] == base[j] && j != vals.base_l)
				|| base[vals.base_l] == '+' || base[vals.base_l] == '-'
				|| (base[vals.base_l] >= 9 && 13 >= base[vals.base_l])
				|| base[vals.base_l] == ' ')
				return (0);
	}
	if (vals.base_l < 2)
		return (0);
	while (str[vals.str_l] != '\0')
		vals.str_l++;
	str = ft_det_sign_cut_str_to_number(str, &vals.sign);
	vals.last_bc = ft_get_index_of_last_num_in_base(str, base);
	return (vals.sign * ft_get_n(str, base, vals.base_l, vals.last_bc));
}
