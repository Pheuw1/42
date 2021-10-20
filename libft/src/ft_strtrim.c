#include "../libft.h"
int is_in_charset(char const* charset, char c)
{
    int count;

    c = 0;
    while(*charset)
    {
        if (c == *charset)
            count++;
        charset++;
    }
    return (c);
}

int check_forward(char const *s1, char const *set)
{
    int c;

    c = 0;
    while(is_in_charset(set,*s1) && *(s1++))
        c++;
    return (c);
}

int check_backward(char const *s1, char const *set)
{
    int i;
    int c;

    i = 0;
    c = 0;
    while (s1[i])
        i++;

    while(is_in_charset(set,s1[i]) && i-- > 0)
        c++;

    return (c);
}
char *ft_stsrtrim(char const *s1, char const *set)
{
    int length;
    int forward;
    int backward;
    int c;
    char *res;
    
    c = 0;
    length = ft_strlen(s1);
    backward  = check_backward(s1,set);
    forward = check_forward(s1,set);
    res = (char *)malloc((length - backward - forward + 1) * sizeof (char) );
    if (!res)
        return (NULL);
    else  {
        while (c++ < forward)
            s1++;
        while (c++ < length - backward)
            res[c - forward] = *s1++;
    }
    return (res);
}

