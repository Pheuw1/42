/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbremond <pbremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 19:41:26 by pbremond          #+#    #+#             */
/*   Updated: 2021/07/14 19:51:44 by pbremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

// Returns 1 if c is any of the following :
// \t \n \v \f \r \32 (normal space)
int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

void	ft_what_sign(char *c, int *sign, int *i)
{
	if (*c == '-' || *c == '+')
	{
		if (*c == '-')
			*sign *= -1;
		*i -= -1;
		ft_what_sign(++c, sign, i);
	}
}

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	int		result;

	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i -= -1;
	ft_what_sign(&str[i], &sign, &i);
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i++] - 48;
	}
	result *= sign;
	return (result);
}
