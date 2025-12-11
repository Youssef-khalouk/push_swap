/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:05:08 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/11 17:05:17 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

t_node	*initalize_stuck_b(t_node **stuck)
{
	t_node	*tmp;

	tmp = NULL;
	pb(stuck, &tmp);
	pb(stuck, &tmp);
	if (tmp->value < tmp->next->value)
		rb(&tmp);
	return (tmp);
}

void	rotate_back(t_node **stuckb, int rotations, int b_size)
{
	if (rotations < b_size)
	{
		while (rotations--)
			rrb(stuckb);
		return ;
	}
	rotations = (b_size - rotations);
	while (rotations--)
		rb(stuckb);
}

int	process(t_node **stuck, t_node **stuckB, int *min)
{
	if ((*stuck)->value < *min)
	{
		*min = (*stuck)->value;
		pb(stuck, stuckB);
		rb(stuckB);
		return (0);
	}
	if ((*stuck)->value > (*stuckB)->value)
	{
		pb(stuck, stuckB);
		return (0);
	}
	rb(stuckB);
	return (1);
}

void	sort(t_node **stuck, unsigned int size)
{
	t_node	*stuckb;
	int		min;
	int		rotations;
	int		b_size;

	if (size < 2)
		return ;
	stuckb = initalize_stuck_b(stuck);
	b_size = 2;
	min = stuckb->next->value;
	while (*stuck)
	{
		rotations = 0;
		b_size++;
		while (process(stuck, &stuckb, &min))
			rotations ++;
		rotate_back(&stuckb, rotations, b_size);
	}
	while (stuckb)
		pa(stuck, &stuckb);
}
