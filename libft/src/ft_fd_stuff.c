#include "./../libft.h"
void ft_putchar_fd(char c, int fd)
{
    if (fd < 0)
        return ;
    else
        write (fd,&c,1);
}
void ft_putendl_fd(char *s, int fd)
{
    if (fd < 0)
        return ;
    else
    {
        ft_putstr_fd(s,fd);
        write(1, "\n", 1);
    }
}
void ft_putnbr_fd(int n, int fd)
{
    char *nbr;
    
    nbr = ft_itoa(n);
    write(fd,nbr,ft_strlen(nbr));
    free(nbr);
}
void ft_putnbr(int n) {
    char *nbr;

    nbr = ft_itoa(n);
    write(1,nbr,ft_strlen(nbr));
    free(nbr);
}
void ft_putstr_fd(char *s, int fd)
{
    if (fd < 0)
        return;
    else
        write(fd, s, ft_strlen(s));
}