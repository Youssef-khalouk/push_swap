
#include "ft_printf.h"

void    ra(int *a)
{
    int tmp;

    tmp = *a;
    while (1)
    {
        a++;
        if (!*a)
        {
            *(a - 1) = tmp;
            break;
        }
        *(a - 1) = *a;
    }
}

void    ra(int *b)
{
    int tmp;

    tmp = *b;
    while (1)
    {
        b++;
        if (!*b)
        {
            *(b - 1) = tmp;
            break;
        }
        *(b - 1) = *b;
    }
}