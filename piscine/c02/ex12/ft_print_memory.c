/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:00:20 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/07/10 16:00:22 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	ft_isprint(unsigned char c)
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

void	ft_print_address(int n)
{
	int	i;
	int	nb;

	i = 0;
	nb = n;
	while (i < 7)
	{
		write(1, "0", 1);
		i++;
	}
	write(1, "1", 1);
	i = 0;
	while (nb > 15)
	{
		nb /= 16;
		i++;
	}
	write(1, "00000000", 7 - i);
	ft_pint_hex(n);
	write(1, ": ", 2);
}

void	ft_print_16_char_hex(unsigned char *s, int l)
{
	int	i;

	i = 0;
	while (i < l && i < 16)
	{
		if (s[i] < 16 && s[i] != 0)
			write(1, "0", 1);
		if (s[i] == 0)
			write(1, "00", 2);
		if (s[i] > 0)
			ft_pint_hex(s[i]);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		write(1, "  ", 2);
		if (i % 2)
			write(1, " ", 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	int					j;
	unsigned char		*s;

	s = (unsigned char *) addr;
	i = 0;
	j = 0;
	while (i <= (size / 16) && size > 0)
	{
		ft_print_address((long) addr + 16 * i);
		ft_print_16_char_hex(s + 16 * i, size - i * 16);
		j = 0;
		while (j < 16 && (16 * i + j) < size)
		{
			if (!ft_isprint(s[16 * i + j]) && (16 * i + j) < size)
				write(1, ".", 1);
			else
				write(1, &s[16 * i + j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (addr);
}
