#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
void *content;
struct s_list *next;
} t_list;

int ft_strlen(const char *s);
void ft_putchar_fd(char c,int fd);
void ft_putendl_fd(char *s,int fd);
void ft_putnbr_fd(int n,int fd);
void ft_putnbr(int n);
void ft_putstr_fd(char *s,int fd);
int ft_isalpha(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_n_of_digits(unsigned int nbr);
char *ft_itoa(int nbr);
void *ft_memset(void *s,int c,unsigned int len);
void ft_bzero(void *s,int n);
void *ft_memcpy(void *dest,const void *src,int n);
void *ft_memmove(void *dst,const void *src,int len);
void *ft_calloc(int nmemb,int size);
char *ft_strchr(char *s,int c);
char *ft_strchr(char *s,int c);
char *ft_substr(char const *s,unsigned int start,unsigned int len);
char *ft_strmapi(char const *s,char(*f)(unsigned int,char));
int is_in_charset(char const *charset,char c);
int check_forward(char const *s1,char const *set);
int check_backward(char const *s1,char const *set);
char *ft_stsrtrim(char const *s1,char const *set);
void ft_lstadd_back(t_list **alst,t_list *new);
void ft_lstadd_front(t_list **alst,t_list *new);
void ft_lstdelone(t_list *lst,void(*del)(void *));
void ft_lstdelone(t_list *lst,void(*del)(void *));
void ft_lstclear(t_list **lst,void(*del)(void *));
void ft_lstiter(t_list *lst,void(*f)(void *));
t_list *ft_lstlast(t_list *lst);
t_list *ft_lstmap(t_list *lst,void *(*f)(void *),void(*del)(void *));
t_list *ft_lstnew(void *content);
int ft_lstsize(t_list *lst);
#define INTERFACE 0
#define EXPORT_INTERFACE 0
#define LOCAL_INTERFACE 0
#define EXPORT
#define LOCAL static
#define PUBLIC
#define PRIVATE
#define PROTECTED
