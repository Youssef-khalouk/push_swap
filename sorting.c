/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <ykhalouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:05:08 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/18 13:48:46 by ykhalouk         ###   ########.fr       */
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
		write(1, "rb\n", 3);
		times--;
	}
	while (times < 0)
	{
		rrb(stuck);
		write(1, "rrb\n", 4);
		times++;
	}
}

void	move_ra(t_node **stuck, int times)
{
	while (times > 0)
	{
		ra(stuck);
		write(1, "ra\n", 3);
		times--;
	}
	while (times < 0)
	{
		rra(stuck);
		write(1, "rra\n", 4);
		times++;
	}
}

static void	move_rr(t_node **stucka, t_node **stuckb, int times)
{
	while (times > 0)
	{
		rr(stucka, stuckb);
		write(1, "rr\n", 3);
		times--;
	}
	while (times < 0)
	{
		rrr(stucka, stuckb);
		write(1, "rrr\n", 4);
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
		moves = get_moves(*stuck, &stuckb, a_size--, b_size++);
		move_rb(&stuckb, moves.b);
		move_ra(stuck, moves.a);
		move_rr(stuck, &stuckb, moves.ab);
		pb(stuck, &stuckb);
		write(1, "pb\n", 3);
	}
	move_rb(&stuckb, get_rotations(&stuckb, get_max(stuckb), b_size));
	while (stuckb)
	{
		pa(stuck, &stuckb);
		write(1, "pa\n", 3);
	}
}
