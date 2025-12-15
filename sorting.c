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

static int	get_max(t_node *stuck)
{
	int	max;

	max = 0;
	while (stuck)
	{
		if (max < stuck->value)
			max = stuck->value;
		stuck = stuck->next;
	}
	return (max);
}

static void	move_rb(t_node **stuck, int times)
{
	while (times > 0)
	{
		rb(stuck);
		times--;
	}
	while (times < 0)
	{
		rrb(stuck);
		times++;
	}
}

void	move_ra(t_node **stuck, int times)
{
	while (times > 0)
	{
		ra(stuck);
		times--;
	}
	while (times < 0)
	{
		rra(stuck);
		times++;
	}
}

static void	move_rr(t_node **stucka, t_node **stuckb, int times)
{
	while (times > 0)
	{
		rr(stucka, stuckb);
		times--;
	}
	while (times < 0)
	{
		rrr(stucka, stuckb);
		times++;
	}
}

void	sort(t_node **stuck, unsigned int size)
{
	t_node	*stuckb;
	int		b_size;
	int		a_size;
	t_moves	moves;

	if (size < 2)
		return ;
	stuckb = initalize_stuck_b(stuck);
	b_size = 2;
	a_size = size - 2;
	while (a_size > 0)
	{
		moves = get_moves(*stuck, &stuckb, a_size, b_size);
		move_rb(&stuckb, moves.b);
		move_ra(stuck, moves.a);
		move_rr(stuck, &stuckb, moves.ab);
		pb(stuck, &stuckb);
		b_size++;
		a_size--;
	}
	move_rb(&stuckb, get_rotations(&stuckb, get_max(stuckb), b_size));
	while (stuckb)
		pa(stuck, &stuckb);
}
