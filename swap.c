/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <ykhalouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:04:57 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/18 13:48:51 by ykhalouk         ###   ########.fr       */
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
	swap(a);
}

void	sb(t_node **b)
{
	swap(b);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
}
