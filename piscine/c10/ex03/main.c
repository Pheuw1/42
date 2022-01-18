#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "ft_h.h"
#include <libgen.h>

int	Check_for_errs(char *path, char * prog)
{
	int		filedesc;
	int		bytes_read;
	char	c;

	c = '\0';
	filedesc = open(path, O_RDONLY);
	bytes_read = read(filedesc, &c, 1);
	if (filedesc < 0)
		fd_error(path, prog);
	else if (bytes_read < 0)
		fd_error(path, prog);
	else
		return (1);
	return (0);
}

int	Check_all_paths_for_errs(int ac, char **av, char* prog)
{
	int		i;
	int		c;

	i = 1;
	c = 1;
	while(i < ac)
		if (!Check_for_errs(av[i],prog))
			c++;
	if (c == i)
		write(2, "Bad file descriptor", 1);
}

int	main(int ac, char **av)
{
	int	i;
	int offset;

	i = 1;
	offset = 0;
	if (ac > 2 && !ft_strcmp((unsigned char *)av[1], (unsigned char *)"-C"))
	{
		while (++i < ac)
			if (Check_all_paths_for_errs(ac, av[i], basename(av[0])))
				line_buffer(av[i], &offset);
	}
	else if (ac == 2 && !ft_strcmp((unsigned char *)av[1],
			(unsigned char *)"-C"))
	{
		stdin_buffer(&offset, 0, 0, 1);
	}
	if (ac > 1 && ft_strcmp((unsigned char *)av[1],
			(unsigned char *)"-C"))
	{
		while (i++ < ac)
			if (Check_all_paths_for_errs(ac, av[i], basename(av[0])))
				line_buffer2(av[i], &offset);
	}
	else if (ac == 1)
	{
		stdin_buffer2(&offset, 0, 0, 1);
	}
}
