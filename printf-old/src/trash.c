#include<stdlib.h>
#include<stddef.h>
#include<stdarg.h>
#include<unistd.h>

void ft_putchar(void *c)
{
    write(1,(char *)c,1);
}

int ft_strlen(char *s)
{
    int i;
    i = 0;
    while(s[i])
        i++;
    return (i);
}
void pc(char a)
{
	write(1,&a,1);
}

void	ft_putnbr(int nb)
{	
	unsigned int	n;
	
	if (nb < 0)
	{
		pc('-');
		n = nb *-1;
	}
	else
		n = nb;

	if (nb >= 10)
		ft_putnbr(n/10);
	pc(n%10 + 48);
}
void	ft_putstr(void *str)
{
    
    write(1,(char *)str,ft_strlen(str));
}


void init_flags(void)
{
    char *flags = "cspdiuxX";
    
    void (*funcs[ft_strlen(flags)]) (void *);
    funcs[0] = ft_putchar;
    funcs[1] = ft_putstr;
    // funcs[2] = ;
    // funcs[3] = ;
    // funcs[4] = ;
    // funcs[5] = ;
    // funcs[6] = ;
    // funcs[7] = ;
    // funcs[8] = ;
    // funcs[9] = ;

}



double average(int num,...) {

   va_list vl;
   double sum = 0.0;

   /* initialize valist for num number of arguments */
   va_start(vl, num);

   /* access all the arguments assigned to valist */
   for (int i = 0; i < num; i++) {
      sum += va_arg(vl, int);
   }
	
   /* clean memory reserved for valist */
   va_end(vl);

   return sum/num;
}

int ft_printf(const char *format, ...)
{
    int     num;
    int     i;
    va_list vl;
    va_start(vl, num);

    i = -1;
    while (++i < num)
    {
        /*check for flags*/


    }



    va_end(vl);
}

int main()
{
    int a = 0;
    printf("|%p|",&a);
    return (0);
}