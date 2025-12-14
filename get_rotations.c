/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rotations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:57:56 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/14 13:58:02 by ykhalouk         ###   ########.fr       */
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

static void	init_min_max(t_node *stuckb, int *min, int *max)
{
	int	min1;
	int	max1;

	if (!stuckb)
		return ;
	min1 = stuckb->value;
	max1 = stuckb->value;
	while (stuckb)
	{
		if (stuckb->value < min1)
			min1 = stuckb->value;
		else if (stuckb->value > max1)
			max1 = stuckb->value;
		stuckb = stuckb->next;
	}
	*min = min1;
	*max = max1;
}

static int	get_value_pos(t_node *stuck, int value)
{
	int	pos;

	pos = 0;
	while (stuck->value != value)
	{
		stuck = stuck->next;
		pos++;
	}
	return (pos);
}

int	get_rotations(t_node **stuckb, int value, int size)
{
	t_node	*tmp;
	int		pos;
	int		min;
	int		max;

	tmp = *stuckb;
	pos = 0;
	init_min_max(*stuckb, &min, &max);
	if (value <= min)
		pos = 1 + get_value_pos(*stuckb, min);
	else if (value >= max)
		pos = get_value_pos(*stuckb, max);
	else
	{
		while (tmp)
		{
			pos++;
			if (tmp->next && tmp->value > value && tmp->next->value <= value)
				break ;
			tmp = tmp->next;
		}
	}
	return ((pos <= size / 2) * pos + (pos > size / 2) * (pos - size));
}
