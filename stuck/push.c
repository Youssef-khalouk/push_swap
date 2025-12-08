
#include "ft_printf.h"

void    pa(int *a, int *b)
{
    if (!*b)
        return ;
    *a = *b;
    ft_printf("pa\n");
}

void    pb(int *a, int *b)
{
    if (!*a)
        return ;
    *b = *a;
    ft_printf("pb\n");
}