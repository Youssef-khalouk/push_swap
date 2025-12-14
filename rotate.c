/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:05:28 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/11 17:05:30 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	rotate(t_node **x)
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

void	ra(t_node **a)
{
	if (rotate(a))
		write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	if (rotate(b))
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	int	_a;
	int	_b;

	_a = rotate(a);
	_b = rotate(b);
	if (_a || _b)
		write(1, "rr\n", 3);
}
