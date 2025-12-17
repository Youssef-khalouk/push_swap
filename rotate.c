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
	rotate(a);
}

void	rb(t_node **b)
{
	rotate(b);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
}
