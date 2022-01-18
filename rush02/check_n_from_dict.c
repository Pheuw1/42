char	*is_valid_number(char *str)
{
	char	*start;
	int		sign;

	sign = 1;
	start = NULL;
	while ((*str >= 9 && *s <= 13) || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (*str == '0' && *(str + 1) != '\0')
		str++;
	start = str;
	if (sign == -1)
		return (NULL);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (NULL);
		str++;
	}
	return (start);
}