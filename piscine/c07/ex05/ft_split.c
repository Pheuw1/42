#include <stdlib.h>
#include <stddef.h>
int	ft_is_sep(char c1, char c2) {
	return (c1==c2);
}

int	ft_str_length(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_sep(str[i], c))
		i++;
	return (i);
}

int	ft_count_strings(char *str, char c1)
{
	int	i;
	int	c;

	c = 0;
	while (*str)
	{
		while (*str && ft_is_sep(*str, c1))
			str++;
		i = ft_str_length(str, c1);
		str += i;
		if (i)
			c++;
	}
	return (c);
}

char	*ft_strcpy(char *str, int n)
{
	char	*dest;

	dest = malloc((n + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	dest[n] = '\0';
	while (n--)
		dest[n] = str[n];
	return (dest);
}

char	**ft_split(char *str, char c)
{
	int		n;
	int		i;
	int		j;
	char	*tmp;
	char	**strings;

	n = ft_count_strings(str, c);
	if (n >= 0)
		strings = malloc((n + 1) * sizeof(char *));
	i = -1;
	while (++i < n)
	{
		j = 0;
		while (ft_is_sep(*str, c) && *str)
			str++;
		tmp = str;
		while (!ft_is_sep(*str, c) && *str)
		{
			j++;
			str++;
		}
		strings[i] = ft_strcpy(tmp, j);
	}
	strings[n] = NULL;
	return (strings);
}

int	main()
{
	char **result;
	int	i;
	char str[] = "test, , , hello, bye, world";
	printf("\"%s\" \"%s\"\n", str, ", ");
	printf("expecting 5 found : ");
	result = ft_split(str, ", ");
	i = 0;
	while (result[i] != NULL)
	{
		printf("New element\n");
		printf("%s\n", result[i]);
		i++;
	}
	char str2[] = "test2";
	printf("\n\n\"%s\" \"%s\"\n", str2, ", ");
	printf("expecting 2 found : ");
	result = ft_split(str2, ", ");
	i = 0;
	while (result[i] != NULL)
	{
		printf("New element\n");
		printf("%s\n", result[i]);
		i++;
	}
	 
	const char str3[] = "                   ";
	const char spe3[] = "   ";
	printf("\n\n\"%s\" \"%s\"\n", str3, spe3);
	printf("expecting 1 found : ");
	result = ft_split(str3, spe3);
	i = 0;
	while (result[i] != NULL)
	{
		printf("New element\n");
		printf("%s\n", result[i]);
		i++;
	}
	
	char str4[] = "                                         ";
	printf("\n\n\"%s\" \"%s\"\n", str4, "     ");
	printf("expecting 1 found : ");
	result = ft_split(str4, "    ");
	i = 0;
	while (result[i] != NULL)
	{
		printf("New element\n");
		printf("%s\n", result[i]);
		i++;
	}
}