#include <unistd.h>

unsigned int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

inline void	ft_swap_strings(char **stringref1, char **stringref2)
{
	char	*tmp;

	tmp = *stringref2;
	*stringref2 = *stringref1;
	*stringref1 = tmp;
}

void	ft_bubble_sort_str_tab(char **tab, int size, int(*cmp)(char *, char *))
{
	int	i;
	int	j;
	int	flag;

	flag = 1;
	while (flag)
	{
		flag = 0;
		i = -1;
		while (++i < size)
		{
			j = -1;
			while (++j < size - i - 1)
			{
				if (cmp(tab[j], tab[j + 1]) > 0)
				{
					flag = 1;
					ft_swap_strings(&tab[j], &tab[j + 1]);
				}
			}
		}
	}
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	if (!i)
		return ;
	ft_bubble_sort_str_tab(tab, i, cmp);
}
