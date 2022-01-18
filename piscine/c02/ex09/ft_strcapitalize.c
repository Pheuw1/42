/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 15:59:48 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/07/10 15:59:48 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	lc(char c)
{
	if (c <= 'z' && c >= 'a')
		return (1);
	else
		return (0);
}

static int	uc(char c)
{
	if (c <= 'Z' && c >= 'A')
		return (1);
	else
		return (0);
}

static int	num(char c)
{
	if (c <= '9' && c >= '0')
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	state;
	int	i;

	i = 0;
	state = 0;
	while (str[i] != '\0')
	{
		if (state == 1 && uc(str[i]))
			str[i] += 'a' - 'A';
		if (uc(str[i]) || lc(str[i]) || num(str[i]))
		{
			if (state == 0)
			{
				if (lc(str[i]))
					str[i] -= 'a' - 'A';
				state = 1;
			}
		}
		else
			state = 0;
		i++;
	}
	return (str);
}
