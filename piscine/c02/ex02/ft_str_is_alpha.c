/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:13:07 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/07/10 16:13:08 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	lc(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

static int	uc(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(uc(str[i]) || lc(str[i])))
			return (0);
		i++;
	}
	return (1);
}
