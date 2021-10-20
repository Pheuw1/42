#include "../libft.h"
void ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list *e;
    
    if (!alst || !(*alst) || !new)
        return;
    e = *alst;
    while(e->next)
        e = e->next;
    e->next = new;

}