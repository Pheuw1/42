#include "ft_h.h"

int	ft_is_print(unsigned char c)
{
	if ((c >= 0 && c <= 31) || c >= 127)
		return (0);
	return (1);
}

void	ft_pint_hex(int n)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
	{
		ft_pint_hex(n / 16);
	}
	write(1, &hex[n % 16], 1);
}


void	ft_print_offset(int n)
{
	int	i;
	int	nb;

	nb = n;
	i = 0;
	while (nb > 15)
	{
		nb /= 16;
		i++;
	}
	write(1, "0000000", 7 - i);
	ft_pint_hex(n);
}

void	ft_print_offset2(int n)
{
	int	i;
	int	nb;

	nb = n;
	i = 0;
	while (nb > 15)
	{
		nb /= 16;
		i++;
	}
	write(1, "000000", 6 - i);
	ft_pint_hex(n);
}


void	ft_print_16_char_hex(unsigned char *s, int l)
{
	int	i;

	i = 0;
	write(1," ",1);
	while (i < l && i < 16)
	{
		write(1," ",1);
		if (s[i] < 16 && s[i] != 0)
			write(1, "0", 1);
		if (s[i] == 0)
			write(1, "00", 2);
		if (s[i] > 0)
			ft_pint_hex(s[i]);
		i++;
		if (i == 8)
			write(1," ",1);
	}
	while (i < 16)
	{	
		if (i == 8)
			write(1," ",1);
		write(1, "   ", 3);
		i++;
	}
}

void	ft_print_16_char_hex2(unsigned char *s, int l)
{
	int	i;

	i = 0;
	while (i < l && i < 16)
	{
		write(1," ",1);
		if (s[i] < 16 && s[i] != 0)
			write(1, "0", 1);
		if (s[i] == 0)
			write(1, "00", 2);
		if (s[i] > 0)
			ft_pint_hex(s[i]);
		i++;
	}
	while (i < 16)
	{	
		write(1, "   ", 3);
		i++;
	}
}