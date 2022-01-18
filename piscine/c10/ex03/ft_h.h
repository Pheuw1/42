#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
int	ft_is_print(unsigned char c);
void	ft_pint_hex(int n);
void	ft_print_offset(int n);
void	ft_print_16_char_hex(unsigned char *s, int l);
unsigned int	ft_strlen(unsigned char *s);
int	ft_strcmp(unsigned char *s1, unsigned char *s2);
unsigned char	*ft_strdup(unsigned char *src);
void ft_display_line(unsigned char *line_buffer,int size, int offset);
void line_buffer(char *path, int *offset);
void stdin_buffer();
void line_buffer2(char *path, int *offset);
void	ft_display_line2(unsigned char *line_buffer, int size, int offset);
void	ft_print_offset2(int n);
void	ft_print_16_char_hex2(unsigned char *s, int l);
void	stdin_buffer2(int *offset, int bytes_read, unsigned char *line_buffer, int flag);
int	fd_error(char *filename, char *app_name);

#endif