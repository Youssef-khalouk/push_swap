#include "ft_push_swap.h"
#include "printf/ft_printf.h"

void    pa(t_node **a, t_node **b)
{
    t_node  *tmp;

    if (!b)
        return ;
    tmp = *b;
    *b = (*b)->next;
    tmp->next = *a;
    *a = tmp;
    ft_printf("pa\n");
}

void    pb(t_node **a, t_node **b)
{
    t_node  *tmp;

    if (!a)
        return ;
    tmp = *a;
    *a = (*a)->next;
    tmp->next = *b;
    *b = tmp;
    ft_printf("pb\n");
}
