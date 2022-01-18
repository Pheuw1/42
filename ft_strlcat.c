int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_l;
	unsigned int	src_l;

	dest_l = ft_strlen(dest);
	src_l = ft_strlen(dest);
	i = 0;
	if (size <= dest_l)
		src_l += size;
	else
		src_l += dest_l;
	while (src[i] && i + 1 < size)
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i + 1] = '\0';
	return (src_l);
}


// 8=========D ~~~~