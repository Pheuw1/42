
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
			ft_putchar(table[j][i] + '0');
			if (j < n - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

void ft_print_table_with_vals(int table[9][9], povs[4][9])
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

void ft_init_c_vals(t_vals *indexes)
{
	indexes->i[0]          = -1;
	indexes->i[1]          = n;
	indexes->max[0]        = 0;
	indexes->max[1]        = 0;
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

int ft_check_left_inter(int table[9][9], int povs[4][9], t_pos *p)
{
	int i;
	int max;
	int vc;

	i   = -1;
	max = 0;
	vc  = 0;

	while (++i < n)
	{
		if (max < table[i][p->y])
		{
			max = table[i][p->y];
			vc++;
		}
	}
	if (table[p->x][p->y] == n && vc < povs[2][p->y])
		return (0);

	if (vc > povs[2][p->y])
		return (0);
	return (1);
}

int ft_check_left(int table[9][9], int povs[4][9], t_pos *p)
{
	int i;
	int max;
	int vc;

	i   = -1;
	max = 0;
	vc  = 0;
	while (++i < n)
	{
		if (max < table[i][p->y])
		{
			max = table[i][p->y];
			vc++;
		}
	}
	if (vc != povs[2][p->y])
		return (0);
	return (1);
}

int ft_check_right(int table[9][9], int povs[4][9], t_pos *p)
{
	int i;
	int max;
	int vc;

	i   = n;
	max = 0;
	vc  = 0;
	while (--i > 0)
	{
		if (max < table[i][p->y])
		{
			max = table[i][p->y];
			vc++;
		}
	}
	if (vc > povs[3][p->y])
		return (0);
	return (1);
}
int ft_check_up(int table[9][9], int povs[4][9], t_pos *p)
{
	int i;
	int max;
	int vc;

	i   = n;
	max = 0;
	vc  = 0;
	while (--i > 0)
	{
		if (max < table[p->x][i])
		{
			max = table[p->x][i];
			vc++;
		}
	}
	if (vc > povs[1][p->x])
		return (0);
	return (1);
}
int ft_check_down_inter(int table[9][9], int povs[4][9], t_pos *p)
{
	int i;
	int max;
	int vc;

	i   = -1;
	max = 0;
	vc  = 0;
	while (++i < n)
	{
		if (max < table[p->x][i])
		{
			max = table[p->x][i];
			vc++;
		}
	}
	if (vc > povs[0][p->x])
		return (0);

	return (1);
}

int ft_check_down(int table[9][9], int povs[4][9], t_pos *p)
{
	int i;
	int max;
	int vc;

	i   = -1;
	max = 0;
	vc  = 0;
	while (++i < n)
	{
		if (max < table[p->x][i])
		{
			max = table[p->x][i];
			vc++;
		}
	}
	if (vc != povs[0][p->x])
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
// check si la difference de val
// si (n-1) - i < pov_val - view_count

int ft_check(int table[9][9], int povs[4][9], t_pos *p)
{
	ft_print_table_with_vals(table, povs);

	if (ft_check_if_in_row_or_col(table, p))
		return (0);
	if (!ft_check_left_inter(table, povs, p))
		return (0);
	if (!ft_check_down_inter(table, povs, p))
		return (0);
	if (!ft_check_right(table, povs, p))
		return (0);
	if (!ft_check_up(table, povs, p))
		return (0);

	return (1);
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

	i = 0; // side
	j = 0; // val in side
	k = 0; // string iter
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

		if (ft_check(table, povs, p))
		{
			if (ft_backtrack(table, povs, p, c + 1))
				return (1);
			table[p->x][p->y] = 0;
		}
		i++;
	}
	table[p->x][p->y] = 0;

	return (0);
}

// si check si la difference de val
// si (n-1) - i < pov_val - view_count

void rush(char *in_povs)
{
	t_pos p;
	int   table[9][9];
	int   povs[4][9];
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
		if (ft_backtrack(table, povs, &p, 0))
			ft_print_table_with_vals(table, povs);
		else
			write(1, "Error\n", 7);
	}
}

int main(int ac, char **argv)
{
	// char *s = "4 2 2 3 3 3 1 6 2 1 3 2 2 4 3 4 2 2 3 2 5 3 3 4 4 2 1 2 4 4 4 3 1 2 3 2"; 9 should be good doesnt work
	// char *s = "4 3 4 1 5 4 3 2 2 4 2 4 1 3 5 4 3 3 5 2 3 1 3 2 2 1 2 3 2 4 3 3";//8 should be good doesnt work
	// char *s = "1 3 4 4 4 3 2 2 1 2 2 2 4 4 1 7 4 4 3 3 2 2 1 2 3 2 3 5";//bad solution!
	// char *s = "6 3 2 3 3 1 2 1 2 2 2 3 4 4 4 7 3 3 2 2 1 2 1 2 2 3 3 5";
	// char *s = "1 7 2 5 3 3 2 2 1 2 2 2 3 5 1 6 4 3 3 3 2 4 1 2 3 4 2 4";
	// char *s = "3 2 2 3 2 1 1 2 3 3 2 2 3 4 2 2 1 5 4 2 2 1 2 3";// 6 doesnt work
	char *s = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"; // kinda works stops short of solution
	// char *s = "1 5 3 4 8 7 5 4 2 6 9 8 7 2 5 4 6 3 5 9 8 2 3 5 6 1 7 4 7 4 5
	// 2 1 9 9 5"; char *s = "3 2 1 1 2 1 2 3 2 1 2 3";

	rush(s);
}