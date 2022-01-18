#include "ft_h.h"
#include <fcntl.h>
#include <unistd.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

void line_buffer2(char *path,int *offset)
{
	unsigned char	file_buffer[16];
	unsigned char	*line_buffer;
	int				filedesc;
	int				bytes_read;
	int				flag;

	flag = 0;
	bytes_read = 1;
	line_buffer = NULL;
	filedesc = open(path, O_RDONLY);
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
			ft_display_line2((&file_buffer[0]), bytes_read, *offset);
			line_buffer = ft_strdup(file_buffer);
			flag = 0;
		}
		*offset += bytes_read;
	}
	close(filedesc);
}

void	ft_display_line2(unsigned char *line_buffer, int size, int offset)
{
	ft_print_offset2(offset);
	if (size)
		ft_print_16_char_hex2(line_buffer, size);
	write(1, "\n", 1);
}


void	stdin_buffer2(int *offset, int bytes_read, unsigned char *line_buffer
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
				ft_display_line2((&file_buffer[0]), bytes_read, *offset);
				line_buffer = ft_strdup(file_buffer);
			}
			bytes_read = 0;
			*offset += bytes_read;
		}
	}
	ft_display_line2((&file_buffer[0]), bytes_read, *offset);
}
