/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <gmehdevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:04:36 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/11/23 20:08:14 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_sep(char c1, char c2)
{
	return (c1 == c2);
}

int	ft_str_length(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_sep(str[i], c))
		i++;
	return (i);
}

int	ft_count_strings(const char *str, char c1)
{
	int	i;
	int	c;

	c = 0;
	while (*str)
	{
		while (*str && ft_is_sep(*str, c1))
			str++;
		i = ft_str_length(str, c1);
		str += i;
		if (i)
			c++;
	}
	return (c);
}

static char	*ft_strncpy(const char *str, int n)
{
	char	*dest;

	dest = (char *)malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[n] = '\0';
	while (n--)
		dest[n] = str[n];
	return (dest);
}

char	**ft_split(const char *str, char c)
{
	int		n[3];
	char	*tmp;
	char	**strings;

	n[0] = ft_count_strings(str, c);
	strings = NULL;
	if (n[0] >= 0)
		strings = (char **)malloc((n[0] + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	n[1] = -1;
	while (++n[1] < n[0])
	{
		n[2] = 0;
		while (ft_is_sep(*str, c) && *str)
			str++;
		tmp = (char *)str;
		while (!ft_is_sep(*str, c) && *(str++))
			n[2]++;
		strings[n[1]] = ft_strncpy(tmp, n[2]);
	}
	strings[n[0]] = NULL;
	return (strings);
}
