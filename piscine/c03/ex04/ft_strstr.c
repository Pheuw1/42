/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:34:54 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/07/13 21:34:55 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	o;

	i = 0;
	if (!to_find[0])
		return (str);
	while (str[i])
	{
		o = 0;
		while (to_find[o])
		{
			if (str[i + o] == to_find[o])
				o++;
			else
				break ;
		}
		if (!to_find[o])
			return (&str[i]);
		i++;
	}
	return (0);
}
