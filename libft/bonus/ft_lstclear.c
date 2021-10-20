#include "../libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void*)) {
    del(lst->content);
    free(lst);
}

void ft_lstclear(t_list **lst, void (*del)(void*)) {
    t_list *tmp;
    t_list *e;

    if (!lst || !(*lst))
        return;
    e = *lst;
    while(e->next) {
        tmp = e;
        e = e->next;
        del(e->content);
        free(tmp);
    }
}