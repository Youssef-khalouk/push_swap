/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:05:38 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/11 17:05:40 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	rra(t_node	**a)
{
	if (revers(a))
		write(1, "rra\n", 4);
}

void	rrb(t_node	**b)
{
	if (revers(b))
		write(1, "rrb\n", 4);
}

void	rrr(t_node	**a, t_node	**b)
{
	int	_a;
	int	_b;

	_a = revers(a);
	_b = revers(b);
	if (_a || _b)
		write(1, "rrr\n", 4);
}
