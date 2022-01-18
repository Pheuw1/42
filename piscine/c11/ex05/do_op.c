#include "ft.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_get_index(char c)
{
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '/')
		return (2);
	else if (c == '*')
		return (3);
	else if (c == '%')
		return (4);
	return (0);
}

int	main(int c, char **ss)
{
	void	(*fs[5])(int, int);

	fs[0] = &ft_sum;
	fs[1] = &ft_sub;
	fs[2] = &ft_div;
	fs[3] = &ft_mul;
	fs[4] = &ft_mod;
	if (c < 4)
		return (0);
	else if (ss[2][0] != '+' && ss[2][0] != '-'
			&& ss[2][0] != '*' && ss[2][0] != '/' && ss[2][0] != '%')
		write(1, "0", 1);
	else
		fs[ft_get_index(ss[2][0])]((ft_atoi(ss[1])), (ft_atoi(ss[3])));
	return (0);
}
