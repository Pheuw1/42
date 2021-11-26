#include "ft_printf.h"

void left_padding(int len, t_print *tab)
{
	if (tab->width > len && !tab->minus)
		while (--tab->width - tab->prec > len)
			tab->tl += write(1, " ", 1);
}

void right_padding(int len, t_print *tab)
{
	if (tab->width > len && tab->minus)
		while (tab->width-- - tab->prec > len)
			tab->tl += write(1, " ", 1);
}

void zero_padding(int len, t_print *tab)
{
	if (tab->dot)
	{
		while ((--tab->prec - tab->width + tab->plus) > len)
			tab->tl += write(1, "0", 1);
	}
	else if (tab->zero)
		while (--tab->width - tab->width + tab->plus > len)
			tab->tl += write(1, "0", 1);
}
