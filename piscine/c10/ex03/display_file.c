#include "ft_h.h"
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>
//#include <sys/types.h> might need to include that
//#include <sys/stat.h>   might need to include that

//    read : On success, the number of bytes read is returned (zero indicates
//    end of file), and the file position is advanced by this number.
//    It is not an error if this number is smaller than the number of
//    bytes requested;

unsigned int	ft_strlen(unsigned char *str);

int	fd_error(char *filename, char *app_name)
{
	if (errno)
	{
		write(2, basename(app_name),
			ft_strlen((unsigned char *)basename(app_name)));
		write(2, ": ", 2);
		write(2, filename, ft_strlen((unsigned char *)filename));
		write(2, ": ", 2);
		write(2, strerror(errno), ft_strlen((unsigned char *)strerror(errno)));
		write(2, "\n", 1);
		return (1);
	}
	return (0);
}

void	ft_display_line(unsigned char *line_buffer, int size, int offset)
{
	int	j;

	ft_print_offset(offset);
	if (size)
	{
		ft_print_16_char_hex(line_buffer, size);
		j = 0;
		if (size != 0)
			write(1, "  ", 2);
		write(1, "|", 1);
		while (j < size)
		{
			if (!ft_is_print((unsigned char) line_buffer[j]))
				write(1, ".", 1);
			else
				write(1, &line_buffer[j], 1);
			j++;
		}
		if (size != 0)
			write(1, "|", 1);
	}
	write(1, "\n", 1);
}

void line_buffer(char *path, int *offset)
{
	unsigned char	file_buffer[16];
	unsigned char	*line_buffer;
	int				filedesc;
	int				bytes_read;
	int				flag;

	flag = 0;
	line_buffer = NULL;
	filedesc = open(path, O_RDONLY);
	bytes_read = 1;
	while (bytes_read > 0 && filedesc >= 0)
	{
		bytes_read = read(filedesc, &file_buffer[0], 16);
		if (bytes_read && line_buffer && !ft_strcmp(line_buffer, file_buffer))
		{	
			if (flag)
				write(1, "*\n", 2);
			flag = 0;
		}
		else
		{
			ft_display_line((&file_buffer[0]), bytes_read, *offset);
			line_buffer = ft_strdup(file_buffer);
			flag = 0;
		}
		*offset += bytes_read;
	}
	close(filedesc);
}

void	stdin_buffer(int *offset, int bytes_read, unsigned char *line_buffer
, int flag)
{
	unsigned char	file_buffer[16];
	int				ret;

	while (1)
	{
		ret = read(0, &file_buffer[bytes_read], 1);
		if (ret != 0)
			bytes_read += ret;
		else
			break ;
		if (bytes_read > 15)
		{
			if (line_buffer && !ft_strcmp(line_buffer, file_buffer))
			{	
				if (flag)
					write(1, "*\n", 2);
				flag = 0;
			}
			else
			{
				flag = 1;
				ft_display_line((&file_buffer[0]), bytes_read, *offset);
				line_buffer = ft_strdup(file_buffer);
			}
			*offset += bytes_read;
			bytes_read = 0;
		}
	}
	ft_display_line((&file_buffer[0]), bytes_read, *offset);
}
