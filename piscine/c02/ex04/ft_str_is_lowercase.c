/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:13:19 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/07/10 16:13:20 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	lc(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(lc(str[i])))
			return (0);
		i++;
	}
	return (1);
}
