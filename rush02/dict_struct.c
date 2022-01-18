#include <stdlib.h>
#include <stddef.h>
#include <fcntl.h>
#include <unistd.h>

//TODO PAS DE : = nique ta mere
//TODO PAS DE ligne vide;
typedef struct s_Dict{
	char * key;
	char * value;
} t_Dict;


char	*is_valid_number(char *str)
{
	char	*start;
	int		sign;

	sign = 1;
	start = NULL;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
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


int ft_is_printable(char *str)
{
	while (!((*str >= 0 && *str <= 31) || *str >= 127) && *str)
		str++;
	if(!*str)
		return (1);
	return (0);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	ss;

	ss = 0;
	while (src[ss])
		ss++;
	if (ss + 1 < size)
	{
		i = -1;
		while (++i < ss + 1)
			dest[i] = src[i];
	}
	else if (size)
	{
		i = -1;
		while (++i < size - 1)
			dest[i] = src[i];
		dest[i] = '\0';
	}	
	return (ss);
}

char	*ft_strdup_line(char *src, char c)
{
	char	*copy;
	int		i;
	int 	j;
	int 	size;

	i = -1;
	size = 0;
	while(src[++i] != c && src[i])
		if (src[i] != ' ')
			size++;
	copy = (char *)malloc((size + 1)* sizeof(char) );
	if (copy == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (src[++i] && i < size)
	{
		if (src[i] == c)
			break ;
		if (src[i] != ' ')
			copy[++j] = src[i];
	}
	copy[j] = '\0';
	return (copy);
}


// check for errors now


void parse_line(char *path,int line,char **string)
{
	char	file_buffer[32767]; // min before 1999 32,767 bytes
	int		filedesc;
	char 	*start_of_line;
	int		bytes_read;
	int		c;
	int		i;

	filedesc = open(path, O_RDONLY);
	if (filedesc < 0)
		return ;// print error
	bytes_read = 1;
	c = 0;
	i = -1;
	while (bytes_read > 0)
	{
		bytes_read = read(filedesc,&file_buffer[0],32767); //fildesc should be 0 so standard input and other sutff?
		while (file_buffer[++i])
		{
			if (c == line)
				*string = ft_strdup_line(start_of_line,'\n');
			if (file_buffer[i] == '\n')
				start_of_line = &file_buffer[i];
		}
	}
	close(filedesc);
}

int get_n_of_structs(char *path)
{
	char	file_buffer[32767]; // min before 1999 32,767 bytes
	int		filedesc;
	int		bytes_read;
	int		c;
	int		i;

	filedesc = open(path, O_RDONLY);
	if (filedesc < 0)
		return (-1);
	bytes_read = 1;
	c = 0;
	i = -1;
	while (bytes_read > 0)
	{
		bytes_read = read(filedesc,&file_buffer[0],32767); //fildesc should be 0 so standard input and other sutff?
		while (file_buffer[++i])
			if (file_buffer[i] == '\n')
				c++;
	}
	close(filedesc);
	if (!bytes_read)
		return (c);
}


t_Dict *init_dict(char *path)
{
	int i;
	int n;
	t_Dict *dict;
	char * line;

	n = get_n_of_structs(path);
	dict = (t_Dict *)malloc((n+1)*sizeof(t_Dict));
	i = -1;
	if (!dict)
		return (NULL);
	while(++i < n)
	{
		parse_line(path,i,&line);
		make_dict_instance(line,&dict[i]);
		free(line);
	}//use i to free from beggining if any are null
	dict[i].key = NULL;
	return (dict);
}

int make_dict_instance(char *line,t_Dict *instance)
{
	int size1;
	int size2;
	int j;

	size1 = 0;
	size2 = 0;
	j = -1;
	while(line[++j] != ':')
		size1++;
	while(line[++j] != '\0')
		size2++;
	instance->key = (char *)malloc((size1 + 1) * sizeof(char));
	instance->value = (char *)malloc((size2 + 1) * sizeof(char));
	if(!instance->key || !instance->value)// can't really check both at once
		return (NULL);
	else
	{
		ft_strlcpy(instance->key,line,size1);
		if (is_valid_number(instance->key))
		{
			line+=size1;
			if (ft_is_printable(line))
				ft_strlcpy(instance->value,line,size2);
			else
				write(1,"Dict Error\n",11);//return NULL
		}
		else
			write(1,"Dict Error\n",11);//return NULL
	}
}	


int	ft_n_of_digits(unsigned int nbr)
{
	int				i;

	i = 0;
	while (nbr > 10)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

char	*itoa(unsigned int nbr)
{
	int		j;
	char	*str;

	j = ft_n_of_digits(nbr) + 1;
	str = malloc((j + 1) * sizeof(char));
	str[j] = 0;
	j--;
	while (nbr > 10)
	{
		str[j] = nbr % 10 + '0';
		nbr /= 10;
		j--;
	}
	str[j] = nbr % 10 + '0';
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int read_from_dict(char *str,t_Dict *dict)
{
	int i;

	i = -1;
	while(dict[++i].key)
	{	
		if(strcmp(dict[i].key,str) == 0)
		{
			ft_putstr(dict[i].value);
			return (0);
		}
	}
	return (-1);
}


