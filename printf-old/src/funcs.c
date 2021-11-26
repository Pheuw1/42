#include "../ft_printf.h"

void ft_print_putstr(t_print *tab)
{
	const char	*s;

	s = va_arg(tab->args, char *);
	if (s)
		tab->tl += write(1, (char *) s, ft_strlen((char *) s));
	else
		tab->tl += write(1, "(null)", 6);
}

void	ft_print_putchar(t_print *tab)
{
	char	a;

	a = va_arg(tab->args, int);
	tab->tl += write(1, &a, 1);
}

void ft_print_putptr(t_print *tab)
{
	int           i;
	unsigned long dec;
	char          out[9];

	i = -1;
	dec = va_arg(tab->args, unsigned long);
	while (dec > 15)
	{
		out[++i] = tab->ptr_lowhex_set[dec % 16];
		dec = dec / 16;
	}
	out[++i] = tab->ptr_lowhex_set[dec % 16];
	tab->tl += write(1, "0x", 2);
	while (i >= 0)
		tab->tl += write(1, &out[i--], 1);
}
void ft_print_putnbr(t_print *tab)
{
	long long int n;
	char	     *nbr;
	int           len;

	n = va_arg(tab->args, int);
	nbr = ft_itoa((unsigned int)n);
	len = ft_strlen(nbr);
	tab->tl += write(1, nbr, ft_strlen(nbr));
	free(nbr);
}

void ft_print_u_putnbr(t_print *tab)
{
	long long int n;
	char	     *nbr;
	int           len;

	n = va_arg(tab->args, int);
	nbr = ft_itoa((unsigned int)n);
	len = ft_strlen(nbr);
	tab->tl += write(1, nbr, ft_strlen(nbr));
	free(nbr);
}

void ft_print_puthex_upper(t_print *tab)
{
	int          i;
	unsigned int dec;
	char         out[9];

	i = -1;
	dec = va_arg(tab->args, unsigned int);
	if (tab->hashtag && dec)
		tab->tl += write(1, "0X", 2);
	while (dec > 15)
	{
		out[++i] = tab->upphex_set[dec % 16];
		dec = dec / 16;
	}
	out[++i] = tab->upphex_set[dec % 16];
	while (i >= 0)
		tab->tl += write(1, &out[i--], 1);
}

void ft_print_puthex_lower(t_print *tab)
{
	int          i;
	unsigned int dec;
	char         out[9];

	i = -1;
	dec = va_arg(tab->args, unsigned int);
	if (tab->hashtag && dec)
		tab->tl += write(1, "0x", 2);
	while (dec > 15)
	{
		out[++i] = set[dec % 16];
		dec = dec / 16;
	}
	out[++i] = set[dec % 16];
	while (i >= 0)
		tab->tl += write(1, &out[i--], 1);
}

void ft_write_percent(t_print *tab)
{
	tab->tl += write(1, "%", 1);
}
