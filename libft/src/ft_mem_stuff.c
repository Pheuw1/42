#include "./../libft.h"

void *ft_memset(void *s, int c, unsigned int len) {
    unsigned char* p = s;

    while(len--) 
        *(p++) = (unsigned char)c;
    return s;
}

void ft_bzero(void *s, int n) {
    unsigned char *src;
    
    src = (unsigned char *)s;
    while(n--) 
        *(src++) = '\0';
}

void *ft_memcpy(void *dest, const void *src, int n) {
    unsigned char *ret;

    ret = dest;
    if (!dest && !src)
        return (NULL);
    while (n--) 
        ret[n] = ((unsigned char *)src)[n];
    return(dest);
}
void	*ft_memmove(void *dst, const void *src, int len)
{
	int				i;
	unsigned char		*d;
	const unsigned char	*s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	i = 0;
	if (s < d)
		while (++i <= len)
			d[len - i] = s[len - i];
	else
		while (len-- > 0)
			*(d++) = *(s++);
	return (dst);
}
void *ft_calloc(int nmemb, int size)
{
	char *p;

	if (nmemb <= 0 || size <= 0)
		return NULL;

    p = malloc(nmemb * size);
    ft_bzero(p, nmemb * size);
    return p;
}