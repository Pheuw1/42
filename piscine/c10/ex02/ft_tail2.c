#include "ft_tail.h"

void	ft_putstr(char *str)
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

int	check_er(char *path, char *prog_name)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		put_err_str(strerror(errno), path, prog_name);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

void	display(char *path, int n, char *prog_name)
{
	char	c;
	int		i;
	int		fd;
	int		s;

	if (!(check_er(path, prog_name)))
	{
		fd = open(path, O_RDONLY);
		s = 0;
		while (read(fd, &c, 1) > 0)
			s++;
		i = 0;
		close(fd);
		fd = open(path, O_RDONLY);
		while (read(fd, &c, 1) > 0)
		{
			if (s - i <= n)
				write (1, &c, 1);
			i++;
		}
		close(fd);
	}
}

void	put_title(char *path, int put_rl)
{
	char	*temp;

	temp = basename(path);
	if (put_rl)
		write(1, "\n", 1);
	write(1, "==> ", 4);
	while (*temp)
	{
		write(1, temp, 1);
		temp++;
	}
	write(1, " <==\n", 5);
}
