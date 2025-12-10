#include "printf/ft_printf.h"
#include "ft_push_swap.h"

static int rotate(t_node **x)
{
	t_node	*tmp;

	if (!x || !*x || !(*x)->next)
		return (0);
	tmp = *x;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *x;
	*x = (*x)->next;
	tmp->next->next = NULL;
	return (1);
}

void    ra(t_node **a)
{
	if (rotate(a))
		ft_printf("ra\n");
}

void    rb(t_node **b)
{
	if (rotate(b))
		ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	int	_a;
	int	_b;
	_a = rotate(a);
	_b = rotate(b);
	if (_a || _b)
		ft_printf("rr\n");
}