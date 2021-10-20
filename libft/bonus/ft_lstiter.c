#include "../libft.h"

void ft_lstiter(t_list *lst, void (*f)(void *)) {

    t_list *e;

    if (!lst)
        return;

    e = lst;
    while(e->next) {
        f(e->content);
        e = e->next;
    }
}