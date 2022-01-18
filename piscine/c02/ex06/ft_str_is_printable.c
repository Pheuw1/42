/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:59:19 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/07/10 16:13:31 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isprint(char c)
{
	if ((c >= 0 && c <= 31) || c == 127)
		return (0);
	return (1);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(ft_isprint(str[i])))
			return (0);
		i++;
	}
	return (1);
}
