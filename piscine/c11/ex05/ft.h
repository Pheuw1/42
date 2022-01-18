#ifndef FT_H
# define FT_H
void				ft_putchar(char c);
void				ft_putnbr(int nb);
unsigned int		power_of(unsigned int nb, int power);
struct s_int_charp	check_sign_sstart(char *s);
int					latoi(char *s, int l);
int					ft_atoi(char *s);
void				ft_putstr(char *str);
int					ft_strlen(char *str);
void				ft_sum(int a, int b);
void				ft_sub(int a, int b);
void				ft_div(int a, int b);
void				ft_mul(int a, int b);
void				ft_mod(int a, int b);
struct s_int_charp
{
	int		n;
	char	*cp;
};
#endif