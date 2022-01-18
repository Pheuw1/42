#include <stdio.h>
#include <unistd.h>
// visible rects from pov
static int n;

typedef struct s_table_index
{
	int x;
	int y;
} t_pos;

typedef struct s_check_vals
{
	int i[2];
	int max[2];
	int view_count[2];

} t_vals;

void ft_init_c_vals(t_vals *indexes)
{
	indexes->i[0]          = -1;
	indexes->i[1]          = n;
	indexes->max[0]        = 1;
	indexes->max[1]        = 1;
	indexes->view_count[0] = 0;
	indexes->view_count[1] = 0;
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
int ft_abs(int n)
{
	if (n < 0)
		return (n);
	else
		return (n);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	unsigned int n;

	if (nb < 0)
	{
		n = -nb;
		write(1, "-", 1);
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar(n % 10 + '0');
}

void ft_print_table_with_vals(int table[9][9], int povs[4][9])
{
	int i;
	int j;
	int k;

	k = -1;
	write(1, "  ", 2);
	while (++k < n)
	{
		ft_putchar(povs[0][k] + '0');
		write(1, " ", 1);
	}
	write(1, "\n ----------------------------", n * 2 + n / 2);
	write(1, "\n", 1);

	i = -1;
	while (++i < n)
	{
		ft_putchar(povs[2][i] + '0');
		ft_putchar('|');
		j = -1;
		while (++j < n)
		{
			ft_putchar(table[j][i] + '0');
			if (j < n - 1)
				write(1, " ", 1);
		}
		ft_putchar('|');
		ft_putchar(povs[3][i] + '0');
		if (i < n - 1)
			write(1, "\n", 1);
	}
	k = -1;
	write(1, "\n ----------------------------", n * 2 + n / 2);
	write(1, "\n", 1);
	write(1, "  ", 2);
	while (++k < n)
	{
		ft_putchar(povs[1][k] + '0');
		write(1, " ", 1);
	}
	write(1, "\n\n", 2);
}

// both check after i put value
int ft_check_from_up_down(int table[9][9], int pov[4][9], t_pos *p)
{
	t_vals indexes; // 0 : up | 1 : down

	ft_init_c_vals(&indexes);
	while (++indexes.i[0] < n && --indexes.i[1] > 0)
	{
		if (table[p->x][indexes.i[0]] > indexes.max[0])
		{
			indexes.max[0] = table[p->x][indexes.i[0]];
			indexes.view_count[0]++;
		}
		if (table[p->x][indexes.i[1]] > indexes.max[1])
		{
			indexes.max[1] = table[p->x][indexes.i[1]];
			indexes.view_count[1]++;
		}
		if (indexes.view_count[0] > pov[0][p->x] || indexes.view_count[1] > pov[1][p->x])
			return (0);
	}
	if ((p->y == n -1 && indexes.view_count[0] != pov[0][p->x]) ||(p->y == n -1 && indexes.view_count[1] != pov[1][p->x]))
		return (0);

	return (1);
}

int ft_check_from_left_right(int table[9][9], int pov[4][9], t_pos *p)
{
	t_vals indexes; // 0 : up | 1 : down

	ft_init_c_vals(&indexes);
	while (++indexes.i[0] < n && --indexes.i[1] > 0)
	{
		if (table[indexes.i[0]][p->y] > indexes.max[0])
		{
			indexes.max[0] = table[indexes.i[0]][p->y];
			indexes.view_count[0]++;
		}
		if (table[indexes.i[1]][p->y] > indexes.max[1])
		{
			indexes.max[1] = table[indexes.i[1]][p->y];
			indexes.view_count[1]++;
		}
		if (indexes.view_count[0] > pov[2][p->y] || indexes.view_count[1] > pov[3][p->y])
			return (0);
	}
	if ((p->x == n -1 && indexes.view_count[0] != pov[2][p->y]) || (p->x == n -1 && indexes.view_count[1] != pov[3][p->y]))
		return (0);


	return (1);
}

int ft_check_if_in_row_or_col(int table[9][9], t_pos *p)
{
	int i;

	i = -1;
	while (++i < n)
		if (table[i][p->y] == table[p->x][p->y] && i != p->x)
			return (1);

	i = -1;
	while (++i < n)
		if (table[p->x][i] == table[p->x][p->y] && i != p->y)
			return (1);

	return (0);
}

// before i put value
// si tu trouve la valeur max avant la val de pov c faux
// si n - max_val < pov_val - view_count
// si check si la difference de val
// si (n-1) - i < pov_val - view_count

int ft_check(int table[9][9], int povs[4][9], t_pos *p)
{
	if (!ft_check_from_left_right(table, povs, p) || !ft_check_from_up_down(table, povs, p) || ft_check_if_in_row_or_col(table, p))
		return (0);

	return (1);
}

int ft_backtrack(int table[9][9], int povs[4][9], t_pos *p, int c)
{
	// c is current n value
	int i;
	if (c == n * n)
		return (1);
	i    = 1;
	p->x = c % n;
	p->y = c / n;
	while (i <= n)
	{
		table[p->x][p->y] = i;
		ft_print_table_with_vals(table, povs);
		if (ft_check(table, povs, p))
		{
			if (ft_backtrack(table, povs, p, c + 1))
				return (1);
		}
		i++;
	}
	return (0);
}

void ft_print_table(int table[9][9])
{
	int i;
	int j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
		{
			ft_putchar(table[i][j] + '0');
			if (j < n - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

void ft_init_tab(int table[9][9])
{
	// all 0
	int i;
	int j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			table[i][j] = 0;
	}
}

int ft_init_povs(char *in_povs, int povs[4][9])
{ // inits povs and checks if string is valid
	int i;
	int j;
	int k;

	i = 0;                                  // side
	j = 0;                                  // val in side
	k = 0;                                  // string iter
	n = (int) (ft_strlen(in_povs) / 8) + 1; // global
	while (k < 4 * n * 2 - 1 && i < 4)
	{
		if (in_povs[k] != ' ')
		{
			if (in_povs[k] < '0' || in_povs[k] > n + '0')
				return (0);
			povs[i][j] = in_povs[k] - '0';
			j++;
			if (j >= n)
			{
				j = 0;
				i++;
			}
		}
		k++;
	}
	return (1);
}

// si tu trouve la valeur max avant la val de pov c faux
// si n - max_val < pov_val - view_count
// si check si la difference de val
// si (n-1) - i < pov_val - view_count

void rush(char *in_povs)
{
	int   table[9][9];
	int   povs[4][9];
	t_pos p;
	n = (int) (ft_strlen(in_povs) / 8) + 1;
	ft_init_tab(table);
	if (!ft_init_povs(in_povs, povs))
		write(1, "Error\n", 7);
	else
	{
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < n; j++)
				printf("%d | ", povs[i][j]);
		write(1, "\n", 1);
	}
	if (ft_backtrack(table, povs, &p, 0))
		ft_print_table(table);
	else
		write(1, "Error\n", 7);
}

int main(int ac, char **argv)
{
	char *s = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";

	rush(s);
}