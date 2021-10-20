#include "../libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    unsigned int i;
    char *res;

    i = 0;
    res = (char *)malloc((ft_strlen(s) + 1) * sizeof (char));
    if (!res)
        return (NULL);
    else
    {
        while (*(s++))
            res[i] = f(i,*s);
    }
    return (res);
}