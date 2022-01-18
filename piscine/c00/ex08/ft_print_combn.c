/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmehdevi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:06:07 by gmehdevi          #+#    #+#             */
/*   Updated: 2021/07/11 16:06:27 by gmehdevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_tab(int *tab, int size)
{
	int	i;
	int	c;

	i = 0;
	while (i < size)
	{
		c = tab[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

void	initiate_tab(int *tab)
{
	int	i;

	i = 0;
	while (i < 9)
	{
		tab[i] = i;
		i++;
	}
}

void	put_space(int *tab, int n)
{
	if (!(tab[n - 1] == 9 && tab[0] == 9 - n + 1))
	{
		write(1, ", ", 2);
	}
}

void	adjust(int *i, int *tab, int n)
{
	while (i[0] > 0)
	{
		if (tab[i[0]] > 9 - ((n - 1) - i[0]))
		{
			tab[i[0] - 1]++;
			i[1] = i[0] - 1;
			while (i[1]++ <= n - 1)
			{
				tab[i[1]] = tab[i[1] - 1] + 1;
			}
		}
		i[0]--;
	}
}

void	ft_print_combn(int n)
{
	int	tab[9];
	int	i[2];

	initiate_tab(tab);
	while (tab[0] <= 9 - n + 1)
	{
		print_tab(tab, n);
		put_space(tab, n);
		if (tab[n - 1] >= 9 && n != 1)
		{
			tab[n - 2]++;
			tab[n - 1] = tab[n - 2];
			i[0] = n - 2;
			adjust(i, tab, n);
			tab[n - 1] = tab[n - 2];
		}
		tab[n - 1]++;
	}
}
