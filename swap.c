
#include "printf/ft_printf.h"
#include "ft_push_swap.h"

static int	swap(t_node **x)
{
	t_node	*tmp;

	if ( !x || !(*x) || !(*x)->next)
		return (0);
	tmp = (*x)->next;
	(*x)->next = tmp->next;
	tmp->next = (*x);
	(*x) = tmp;
	return (1);
}

void    sa(t_node **a)
{
	if (swap(a))
		ft_printf("sa\n");
}

void    sb(t_node **b)
{
	if (swap(b))
		ft_printf("sb\n");
}

void    ss(t_node **a, t_node **b)
{
	int	_a;
	int	_b;

	_a = swap(a);
	_b = swap(b);
	if (_a || _b)
		ft_printf("ss\n");
}

