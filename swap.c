/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:04:57 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/11 17:05:01 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	swap(t_node **x)
{
	t_node	*tmp;

	if (!x || !(*x) || !(*x)->next)
		return (0);
	tmp = (*x)->next;
	(*x)->next = tmp->next;
	tmp->next = (*x);
	(*x) = tmp;
	return (1);
}

void	sa(t_node **a)
{
	if (swap(a))
		write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	if (swap(b))
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	int	_a;
	int	_b;

	_a = swap(a);
	_b = swap(b);
	if (_a || _b)
		write(1, "ss\n", 3);
}
