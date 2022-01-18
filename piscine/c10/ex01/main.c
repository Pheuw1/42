#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <libgen.h>

void	ft_putstr(char	*str)
{
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
}

void	put_err_str(char *str, char *path, char *prog_name)
{
	char	*temp;

	ft_putstr(basename(prog_name));
	write(2, ": ", 2);
	temp = path;
	while (*temp)
	{
		write(2, temp, 1);
		temp++;
	}
	write(2, ": ", 2);
	while (*str)
	{
		write(2, str, 1);
		str++;
	}
	write(2, "\n", 1);
}

void	folder_err(char *path, char *prog_name)
{
	char	*temp;

	temp = path;
	ft_putstr(basename(prog_name));
	write(2, ": ", 2);
	while (*temp)
	{
		write(2, temp, 1);
		temp++;
	}
	write(2, ": Is a directory\n", 16);
	write(2, "\n", 1);
}

void	display(char *path, char *prog_name)
{
	int		fd;
	int		er;
	char	c;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		put_err_str(strerror(errno), path, prog_name);
	else
	{
		er = read(fd, &c, 1);
		if (er == -1)
			folder_err(path, prog_name);
		else if (er != 0)
		{
			write(1, &c, 1);
			while (read(fd, &c, 1) > 0)
			{
				write(1, &c, 1);
			}
		}
	}
}

int	main(int ac, char **av)
{
	char	c;
	int		i;

	i = 0;
	if (ac == 1)
		while (read(0, &c, 1))
			write(1, &c, 1);
	else
	{
		while (++i < ac)
		{
			if (*av[i] == '-')
				while (read(0, &c, 1))
					write(1, &c, 1);
			else
				display(av[i], av[0]);
		}
	}
}
