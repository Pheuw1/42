#include "../ft_printf.h"

void reset_tab(t_print *tab)
{
	int  i;
	int *set;

	i = -1;
	set = &(tab->tl) + 1; // dont reset tab tl
	while (++i < 9)
		*(set + i) = 0;
}

void	destroy_tab(t_print *tab)
{
	free(tab->specifiers);
	free(tab->ptr_lowhex_set);
	free(tab->upphex_set);
	free(tab);
}

void init_tab(t_print *tab)
{
	int  i;
	int *set;

	i = -1;
	set = &(tab->tl);
	while (++i < 10)
		*(set + i) = 0;
	tab->ft_print_putstr =   ft_print_putstr;
	tab->ft_print_putchar =  ft_print_putchar;
	tab->ft_print_putptr =   ft_print_putptr;
	tab->ft_print_putnbr =   ft_print_putnbr;
	tab->ft_print_u_putnbr =  ft_print_u_putnbr;
	tab->ft_print_puthex_lower = ft_print_puthex_lower;
	tab->ft_print_puthex_upper = ft_print_puthex_upper;
	tab->ft_write_percent = ft_write_percent;
	tab->specifiers = ft_strdup("cspdiuxX%");
	tab->ptr_lowhex_set = ft_strdup("0123456789abcdef");
	tab->upphex_set = ft_strdup("0123456789ABCDEF");
}

t_fct_ptr find_func(char c, t_print *tab, int i)
{
	i = 0;
	while (tab->specifiers[i++])
	{
		if (c == tab->specifiers[i])
		{
			if (!i)
				return (tab->ft_print_putchar);
			else if (i == 1)
				return (tab->ft_print_putstr);
			else if (i == 2)
				return (tab->ft_print_putptr);
			else if (i == 3 || i == 4)
				return (tab->ft_print_putnbr);
			else if (i == 5)
				return (tab->ft_print_u_putnbr);
			else if (i == 6)
				return (tab->ft_print_puthex_lower);
			else if (i == 7)
				return (tab->ft_print_puthex_upper);
			else if (i == 8)
				return (tab->ft_write_percent);
		}
	}
	return (NULL);
}

int find_flags(char c, t_print *tab)
{
	if (c == '-')
		tab->minus = 1;
	else if (c == '0')
		tab->zero = 1;
	else if (c == '#')
		tab->hashtag = 1;
	else if (c == ' ')
		tab->space = 1;
	else if (c == '+')
		tab->plus = 1;
	else
		return (0); // increment string accordingly
	return (1);
}

int width(char *n, t_print *tab)
{
	int nbr;
	int i;

	i = 0;
	nbr = 0;
	while (n[i] >= '0' && n[i] <= '9')
	{
		nbr += nbr * 10 + n[i] - '0';
		i++;
	}
	tab->width = nbr;
	return (i);
}

int precision(char *prec, t_print *tab)
{
	int i;
	int nbr;

	i = 0;
	nbr = 0;
	if (prec[i] == '.')
	{
		tab->dot = 1;
		i++;
		while (prec[i] >= '0' && prec[i] <= '9')
		{
			nbr += nbr * 10 + prec[i] - '0';
			i++;
		}
		tab->prec = nbr;
	}
	return (i);
}

//%[arg_index$][flags][width][.precision]conversion char
int parse_fromat(char *f, t_print *tab)
{
	int i;

	i = 0;
	while (find_flags(f[i], tab))
		i++;
	i += width((char *) &f[i], tab);
	i += precision((char *) &f[i], tab);
	find_func(f[i++], tab, 0)(tab);
	reset_tab(tab);
	return (i);
}

int ft_printf(const char *format, ...)
{
	t_print *tab;
	int      i;

	i = -1;
	tab = (t_print *) malloc(sizeof(t_print));
	if (!tab)
		return (-1);
	init_tab(tab);
	va_start(tab->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			i += parse_fromat((char *) &format[i + 1], tab);
		else
			tab->tl += write(1, &format[i], 1);
	}
	va_end(tab->args);
	i = tab->tl;
	destroy_tab(tab);
	return (i);
}
