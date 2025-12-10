#include "printf/ft_printf.h"
#include "ft_push_swap.h"

static int	revers(t_node	**x)
{
	t_node	*tmp;

	if (!x || !*x || !(*x)->next)
		return (0);
	tmp = *x;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *x;
	*x = tmp->next;
	tmp->next = NULL;
	return (1);
}

void    rra(t_node	**a)
{
	if (revers(a))
		ft_printf("rra\n");
}

void    rrb(t_node	**b)
{
	if (revers(b))
		ft_printf("rrb\n");
}

void    rrr(t_node	**a, t_node	**b)
{
	int	_a;
	int	_b;

	_a = revers(a);
	_b = revers(b);
	if (_a || _b)
		ft_printf("rrr\n");
}