#include "../libft.h"

void ft_lstadd_front(t_list **alst, t_list *new)
{
    if (!new || !alst || !(*alst))
        return;
    new->next = *alst;
}