/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:10:33 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/07/10 16:10:35 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>
static int	lc(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((lc(str[i])))
			str[i] -= 'a' - 'A';
		i++;
	}
	return (str);
}
