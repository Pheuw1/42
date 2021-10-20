#include "./../libft.h"

int ft_isalpha(int c) {
    return  ((c > 'A' && c < 'Z') || (c > 'a' && c < 'z')   ? 1 : 0); 
}

int ft_isdigit(int c) {
    return  ((c > '0' && c < '9' ) ? 1 : 0) ;
}

int ft_isalnum(int c) {
    return ((ft_isalpha(c) || ft_isdigit(c)) ? 1 : 0);
}

int ft_isascii(int c) {
    return (( c >= 0 && c < 128 ) ? 1 : 0);
}


