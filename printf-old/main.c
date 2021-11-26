#include "ft_printf.h"

int main()
{
	int a;

	a = 1;
	// printf("real : III %d ",printf("real : %c%c%c || ",'a','b','c') );printf("I %d III\n",ft_printf("mine : %c%c%c || ",'a','b','c'));
	// printf("real : III %d ",printf("real : %s || ","mauvais") );printf("I %d III\n",ft_printf("mine : %s || ","mauvais"));
	// printf("real : III %d ",printf("real : %u || ",a) );printf("I %d III\n",ft_printf("mine : %u || ",a));
	// printf("real : III %d ",printf("real : %i || ",a) );printf("I %d III\n",ft_printf("mine : %i || ",a));
	// printf("real : III %d ",printf("real : %d || ",a) );printf("I %d III\n",ft_printf("mine : %d || ",a));
	// printf("real : III %d ",printf("real : %p || ",&a) );printf("I %d III\n",ft_printf("mine : %p || ",&a));
	// printf("real : III %d ",printf("real : %#x || ",a) );printf("I %d III\n",ft_printf("mine : %#x || ",a));
	// printf("real : III %d ",printf("real : %#X || ",a) );printf("I %d III\n",ft_printf("mine : %#X || ",a));
	// printf("real : III %d ",printf("real : %% || ") );printf("I %d III\n",ft_printf("mine : %% || "));
	// printf("real : III %d ",printf("real : %X || ",0) );printf("I %d III\n",ft_printf("mine : %X || ",0));
	// printf("real : III %d ",printf("real : %+d || ",a) );printf("I %d III\n",ft_printf("mine : %+d || ",a));
	printf("real : III %d ", printf("real : %10d || ", a));	printf("I %d III\n", ft_printf("mine : %10d || ", a));
	printf("real : III %d ", printf("real : %+10d || ", a));printf("I %d III\n", ft_printf("mine : %+10d || ", a));
	printf("real : III %d ", printf("real : %.10d || ", a));printf("I %d III\n", ft_printf("mine : %.10d || ", a));
	printf("real : III %d ", printf("real : %+.10d || ", a));printf("I %d III\n", ft_printf("mine : %+.10d || ", a));
	printf("real : III %d ", printf("real : %+12.10d || ", a));printf("I %d III\n", ft_printf("mine : %+12.10d || ", a));
	printf("real : III %d ", printf("real : %-+12.9d || ", a));
	printf("I %d III\n", ft_printf("mine : %-+12.9d || ", a));
	printf("real : III %d ", printf("real : %+012d || ", a));
	printf("I %d III\n", ft_printf("mine : %+012d || ", a));
	// printf("real : III %d ",printf("real : %06.6d || ",a) );printf("I %d III\n",ft_printf("mine : %d || ",a));
	// printf("real : III %d ",printf("real : %06.6c || ",a) );printf("I %d III\n",ft_printf("mine : %d || ",a));
	// printf("real : III %d ",printf("real : %06.6x || ",a) );printf("I %d III\n",ft_printf("mine : %d || ",a));
	// printf("real : III %d ",printf("real : %06.6X || ",a) );printf("I %d III\n",ft_printf("mine : %d || ",a));
	// printf("real : III %d ",printf("real : %06.6s || ","something") );printf("I %d III\n",ft_printf("mine : %d || ",a));

	return 0;
}