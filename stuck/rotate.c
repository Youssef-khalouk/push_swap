#include "ft_printf.h"

static int rotate(int *x)
{
	int tmp;
	
	tmp = *x;
	if (!*x || !*(x + 1))
		return (0);
	while (1)
	{
		x++;
		if (!*x)
		{
			*(x - 1) = tmp;
			break;
		}
		*(x - 1) = *x;
	}
	return (1);
}

void    ra(int *a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void    rb(int *b)
{
	if (rotate(b))
		ft_printf("rb\n");
}