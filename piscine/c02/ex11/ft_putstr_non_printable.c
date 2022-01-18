/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:00:09 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/07/11 14:32:14 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_dec_to_hex(unsigned char n)
{
	char	c;

	write(1, "\\", 1);
	if (n / 16 < 10)
	{
		c = '0' + n / 16;
		write(1, &c, 1);
	}
	if (n / 16 >= 10)
	{
		c = 'a' + n / 16 - 10;
		write(1, &c, 1);
	}
	if (n % 16 < 10)
	{
		c = '0' + n % 16;
		write(1, &c, 1);
	}
	if (n % 16 >= 10)
	{
		c = 'a' + n % 16 - 10;
		write(1, &c, 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || *str == 127)
			print_dec_to_hex(*str);
		else
			write(1, str, 1);
		str++;
	}
}
