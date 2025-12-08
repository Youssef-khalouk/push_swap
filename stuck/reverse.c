#include "ft_printf.h"

static int	revers(int *x)
{
	int tmp;
	int i;

	i = 0;
	if (!*x || !*(x + 1))
		return (0) ;
	while (x[i])
		i++;
	tmp = x[--i];
	while (i > 0)
		x[i] = x[--i];
	x[0] = tmp;
	return (1);
}

void    rra(int *a)
{
	if (revers(a))
		ft_printf("rra\n");
}

void    rrb(int *b)
{
	if (revers(b))
		ft_printf("rrb\n");
}

void    rrr(int *a, int *b)
{
	if (revers(a) || revers(b))
		ft_printf("rrr\n");
}