#ifndef FT_TAIL_H
# define FT_TAIL_H
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

void	ft_putstr(char *str);
void	put_err_str(char *str, char *path, char *prog_name);
int		check_er(char *path, char *prog_name);
void	display(char *path, int n, char *prog_name);
void	put_title(char *path, int put_rl);
#endif
