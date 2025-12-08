
#include "ft_printf.h"

void    sa(int *a)
{
    int tmp;

    if (!*a || !*(a + 1))
        return ;
    tmp = *(a + 1);
    *(a + 1) = *a;
    *a = tmp;
    ft_printf("sa\n");
}

void    sb(int *b)
{
    int tmp;

    if (!*b || !*(b + 1))
        return ;
    tmp = *(b + 1);
    *(b + 1) = *b;
    *b = tmp;
    ft_printf("sb\n");
}

void    ss(int *a, int *b)
{
    int tmp;

    if (*a && *(a + 1))
    {
        tmp = *(a + 1);
        *(a + 1) = *a;
        *a = tmp;
        ft_printf("sa\n");
    }
    
    if (*b && *(b + 1))
    {
        tmp = *(b + 1);
        *(b + 1) = *b;
        *b = tmp;
        ft_printf("sb\n");
    }
}

