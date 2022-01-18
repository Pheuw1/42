#include "ft.h"

void	ft_sum(int a, int b)
{
	ft_putnbr(a + b);
}

void	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
}

void	ft_div(int a, int b)
{
	if (b)
		ft_putnbr(a / b);
	else
		ft_putstr("Stop : division by zero");
}

void	ft_mul(int a, int b)
{
	ft_putnbr(a * b);
}

void	ft_mod(int a, int b)
{
	if (b)
		ft_putnbr(a % b);
	else
		ft_putstr("Stop : modulo by zero");
}
