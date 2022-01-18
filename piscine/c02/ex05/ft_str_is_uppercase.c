/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:13:24 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/07/10 16:13:26 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	uc(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(uc(str[i])))
			return (0);
		i++;
	}
	return (1);
}
