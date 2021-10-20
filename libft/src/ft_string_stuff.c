#include "../libft.h"

char *ft_strchr(char *s, int c) {
    char * last;

    last = NULL;
    if (!s--)
        return NULL;
    while (*(++s))
        if (*s == c)
            last = s;
    return(last);
}

char *ft_substr(char const *s, unsigned int start, unsigned int len)
{
    unsigned int i;
    char *sub;

    i = -1;
    sub = (char *)malloc((len+1)*sizeof (char));
    if(!sub)
        return NULL;
    while(++i < len)
        sub[i] = s[start + i];
    
    return sub;
}
