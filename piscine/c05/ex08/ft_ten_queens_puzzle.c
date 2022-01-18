#include<unistd.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (n * -1);
	else
		return (n);
}

void	print_tab(int *grid)
{
	int	i;
	int	c;

	i = 0;
	while (i < 10)
	{
		c = grid[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

unsigned short	is_safe(int *pos_by_col, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n + 1)
	{
		j = 0;
		while (j < n + 1)
		{
			if (i != j)
				if (ft_abs(pos_by_col[i] - pos_by_col[j]) == ft_abs(i - j)
					|| pos_by_col[i] == pos_by_col[j])
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	solve(int *pos_by_col, int n, int c)
{
	int	i;

	i = 0;
	while (i <= 9 && n <= 9)
	{
		pos_by_col[n] = i;
		if (is_safe(pos_by_col, n))
		{
			if (n == 9)
			{
				print_tab(pos_by_col);
				c++;
			}
			c = solve(pos_by_col, n + 1, c);
		}
		i++;
	}
	return (c);
}

int	ft_ten_queens_puzzle(void)
{
	int	tab[10];
	int	i;

	i = 0;
	while (i < 10)
		tab[i++] = 0;
	return (solve(&tab[0], 0, 0));
}
