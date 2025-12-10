#include "printf/ft_printf.h"
#include "ft_push_swap.h"

static int	revers(t_node	**x)
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
	if (revers(a) || revers(b))
		ft_printf("rrr\n");
}