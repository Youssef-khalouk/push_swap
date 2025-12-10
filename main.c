#include "ft_push_swap.h"

int main()
{
    int a[6] = {2, 1, 3, 6, 5, 8 };
    int b[6] = {0, 0, 0, 0, 0, 0 };

    pb(a, b, 6);
    pb(a, b, 6 );

    int i = 0;
    while (i<6)
    {
        ft_printf("%d %c\n", a[i], b[i] == 0 ? ' ' : ('0' + b[i]));
        i++;
    }
    ft_printf("a b\n");

}