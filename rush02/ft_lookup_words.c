#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
//#include <sys/types.h> might need to include that
//#include <sys/stat.h>   might need to include that
//
//
//    read : On success, the number of bytes read is returned (zero indicates
//    end of file), and the file position is advanced by this number.
//    It is not an error if this number is smaller than the number of
//    bytes requested;


void ft_putstr(char *s)
{
	int i;

	i = 0;
	while(*s)
		i++;
	write(1,s,i);
}

typedef struct s_Dict
{
	char *key;
	char *value;
} t_Dict;

char *is_valid_number(char *str)
{
	char *start;
	int   sign;

	sign  = 1;
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
	if (!*str)
		return (1);
	return (0);
}



char *ft_strdup_line(char *src, char c)
{
	char *copy;
	int   i;
	int   j;
	int   size;

	i    = -1;
	copy = (char *) malloc((size + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (src[++i])
	{
		if (src[i] == c)
			break;
		if (src[i] != ' ')
			copy[++j] = src[i];
	}
	copy[j+1] = '\0';
	return (copy);
}

// check for errors now

char * parse_line(char *path, int line)//to free
{
	char  file_buffer[32767]; // min before 1999 32,767 bytes
	int   filedesc;
	char *start_of_line;
	int   bytes_read;
	int   c;
	int   i;

	filedesc = open(path, O_RDONLY);
	if (filedesc < 0)
		return (NULL); // print error
	bytes_read = 1;
	c          = 0;
	i          = -1;
	start_of_line = &file_buffer[0];	
	while (bytes_read > 0)
	{
		bytes_read = read(filedesc, &file_buffer[0], 32767); // fildesc should be 0 so standard input and other sutff?
		while (file_buffer[++i])
		{
			if (c == line)
			{
				start_of_line = &file_buffer[i];
				return (ft_strdup_line(start_of_line, '\n'));
			}
			if (file_buffer[i] == '\n')
				c++;
		}
	}
	close(filedesc);
	return (NULL);
}

int get_n_of_structs(char *path)
{
	char file_buffer[32767]; // min before 1999 32,767 bytes
	int  filedesc;
	int  bytes_read;
	int  c;
	int  i;

	filedesc = open(path, O_RDONLY);
	if (filedesc < 0)
		return (-1);
	bytes_read = 1;
	c          = 0;
	i          = -1;
	while (bytes_read > 0)
	{
		bytes_read = read(filedesc, &file_buffer[0], 32767); // fildesc should be 0 so standard input and other sutff?
		while (file_buffer[++i])
			if (file_buffer[i] == '\n')
				c++;
	}
	close(filedesc);
	return (c);
}

void make_dict_instance(char *line, t_Dict *instance)
{


	instance->key = ft_strdup_line(line, ':');
	if (is_valid_number(instance->key))
	{
		while (*line != ':')
			line ++;
		if (ft_is_printable(line))
			instance->value =  ft_strdup_line(line + 1, '\n');
		else
			write(1, "Dict Error\n", 11); // return NULL
	}
	else
		write(1, "Dict Error\n", 11); // return NULL
}

t_Dict *init_dict(char *path)
{
	int     i;
	int     n;
	t_Dict *dict;
	char *  line;

	n    = get_n_of_structs(path);
	dict = (t_Dict *) malloc((n + 1) * sizeof(t_Dict));
	i    = -1;
	if (!dict)
		return (NULL);
	while (++i < n)
	{
		line = parse_line(path,i);
                       		make_dict_instance(line, &dict[i]);
		free(line);
	} // use i to free from beggining if any are null
	dict[i].key = NULL;
	return (dict);
}



int ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int read_from_dict(char *str, t_Dict *dict)
{
	int i;

	i = -1;
	while (dict[++i].key)
	{
		if (ft_strcmp(dict[i].key, str) == 0)
		{
			ft_putstr(dict[i].value);
			return (0);
		}
	}
	return (-1);
}

unsigned int ft_strlen(char *s) // stuff
{
	unsigned int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char *ft_strdup(char *src1, char *src2) // to free
{
	char *copy;
	int   i;
	int   j;

	copy = malloc((ft_strlen(src1) + ft_strlen(src2) + 1));
	if (copy == NULL)
		return (NULL);
	i = -1;
	j = -1;
	while (src1[++i])
		copy[++j] = src1[i];
	i = -1;
	while (src2[++i])
		copy[++j] = src2[i];
	copy[i] = '\0';
	return (copy);
}

int read_from_dict(char *str, t_Dict *dict);

typedef struct s_Trio
{
	char hundreds;
	char tens;
	char digits;

} t_Trio;

void trio_init_zero(t_Trio *trios, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		trios->hundreds = 0;
		trios->tens     = 0;
		trios->digits   = 0;
		trios++;
	}
}

t_Trio *init_trios(char *str, int *n) //' n is length of trio array//
{
	int     len;
	t_Trio *trios;

	len = ft_strlen(str);\
	*n  = (len / 3);
	if (len % 3)
		*n += 1;
	trios = malloc(*n * sizeof(t_Trio));
	if (!trios)
		return (NULL);
	trio_init_zero(trios, *n);
	*n = 0;
	if (len % 3 == 2)
	{
		trios[*n].tens   = *(str++);
		trios[(*n)++].digits = *(str++);
	}
	else if (len % 3)
		trios[(*n)++].digits = *(str++);
	while (*str)
	{
		trios[(*n)].hundreds = *(str++);
		trios[(*n)].tens     = *(str++);
		trios[(*n)++].digits   = *(str++);
	}
	return (trios);
}

void create_and_look_for_key(char c1, char c2, t_Dict *dict)
{
	char *str;

	str = malloc(3 * sizeof(char));
	if (!str)
		return;
	str[0] = c1;
	str[1] = c2;
	str[2] = 0;
	read_from_dict(str, dict);
	free(str);
}

void spell_trio(t_Trio *trio, t_Dict *dict)
{
	char *tmp;

	if (trio->hundreds != '0')
	{
		create_and_look_for_key(trio->hundreds, 0, dict);
		read_from_dict("100", dict);
	}
	if (trio->tens == '0' && trio->digits != '0')
		create_and_look_for_key(trio->digits, 0, dict);
	else if (trio->tens == '1')
		create_and_look_for_key(trio->digits, trio->tens, dict);
	else if (trio->tens >= '2' && trio->tens <= '9')
	{
		create_and_look_for_key(trio->tens, '0', dict);
		if (trio->digits != '0')
			create_and_look_for_key(trio->digits, 0, dict);
	}
}

char *create_key_thousands(int n) // to free
{
	char *string;
	int   i;

	if (n < 1)
		return (NULL);
	string = (char *) malloc((n * 3 + 2) * sizeof(char));
	if (!string)
		return (NULL);
	string[0] = '1';
	i         = -1;
	while (++i < n * 3 + 1)
		string[i] = '0';
	string[i] = 0;
	return (string);
}

void Spell_Word(char *str, t_Dict *dict)
{
	int     n_of_structs;
	int     len;
	t_Trio *trios;
	int n;
	len = ft_strlen(str);
	n = (len/3)*3;
	trios = init_trios(str, &n_of_structs);
	while (n_of_structs-- > 0)
	{
		len = ft_strlen(str);
		spell_trio(trios, dict);
		if (read_from_dict(create_key_thousands(n), dict) < 0)
			write(1, "Dict Error\n", 11); // return NULL
		trios++;
		n -= 3;
	}

	free(trios);
}
//iterate over all key value paris and free them

int main()
{
	t_Dict *dict;
	char *s = "10001010101010100001001";
	dict = init_dict("./dict.txt");
	Spell_Word(s,dict);
	free(dict);
}
