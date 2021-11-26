#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_print
{
	int		tl;    // total_length (return value)
	int		width; // width
	int		prec;
	int		zero;    // zero padding
	int		dot;     // .
	int		minus;   // text to left of padding | zero,
	int		plus;    // force sign on numbers
	int		space;   // space flag ' '
	int		hashtag; // x/X add prefix 0x/X
	void	(*ft_print_putstr)(struct s_print *);
	void	(*ft_print_putchar)(struct s_print *);
	void	(*ft_print_putptr)(struct s_print *);
	void	(*ft_print_putnbr)(struct s_print *);
	void	(*ft_print_u_putnbr)(struct s_print *);
	void	(*ft_print_puthex_upper)(struct s_print *);
	void	(*ft_print_puthex_lower)(struct s_print *);
	void	(*ft_write_percent)(struct s_print *);
	va_list	args;
	char	*specifiers;
	char	*ptr_lowhex_set;
	char	*upphex_set;
}	t_print;

typedef void	(*t_fct_ptr)(t_print *);
void	ft_print_putchar(t_print *tab);
void	ft_print_putstr(t_print *tab);
void	ft_print_putptr(t_print *tab);
void	ft_print_putnbr(t_print *tab);
void	ft_print_u_putnbr(t_print *tab);
void	ft_print_puthex_lower(t_print *tab);
void	ft_print_puthex_upper(t_print *tab);
void	ft_write_percent(t_print *tab);
int		ft_printf(const char *format, ...);
#endif
