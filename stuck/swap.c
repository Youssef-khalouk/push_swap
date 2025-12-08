
#include "ft_printf.h"

static int	swap(int *x)
{
	int	tmp;

	if (!*x || !*(x + 1))
		return (0);
	tmp = *(x + 1);
	*(x + 1) = *x;
	*x = tmp;
	return (1);
}
void    sa(int *a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void    sb(int *b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void    ss(int *a, int *b)
{
	if (swap(a) || swap(b))
		ft_printf("ss\n");
}

