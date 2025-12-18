/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_0_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <ykhalouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 10:42:16 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/18 13:48:43 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

static int	get_min_pos(t_node **stuck, int size)
{
	int		i;
	int		min;
	int		pos;
	t_node	*stucka;

	i = 0;
	stucka = *stuck;
	min = stucka->value;
	pos = 0;
	while (stucka)
	{
		if (stucka->value < min)
		{
			min = stucka->value;
			pos = i;
		}
		stucka = stucka->next;
		i++;
	}
	return ((pos <= size / 2) * pos + (pos > size / 2) * (pos - size));
}

static void	sort3(t_node **stuck)
{
	if ((*stuck)->value > (*stuck)->next->value
		&& (*stuck)->value > (*stuck)->next->next->value)
	{
		ra(stuck);
		write(1, "ra\n", 3);
	}
	else if ((*stuck)->next->value > (*stuck)->value
		&& (*stuck)->next->value > (*stuck)->next->next->value)
	{
		rra(stuck);
		write(1, "rra\n", 4);
	}
	if ((*stuck)->value > (*stuck)->next->value)
	{
		sa(stuck);
		write(1, "sa\n", 3);
	}
}

static void	sort5(t_node **stuck, t_node **stuckb)
{
	move_ra(stuck, get_min_pos(stuck, 5));
	pb(stuck, stuckb);
	write(1, "pb\n", 3);
	move_ra(stuck, get_min_pos(stuck, 4));
	pb(stuck, stuckb);
	write(1, "pb\n", 3);
	sort3(stuck);
	pa(stuck, stuckb);
	pa(stuck, stuckb);
	write(1, "pa\npa\n", 6);
}

static void	sort6(t_node **stuck, t_node **stuckb)
{
	move_ra(stuck, get_min_pos(stuck, 6));
	pb(stuck, stuckb);
	write(1, "pb\n", 3);
	move_ra(stuck, get_min_pos(stuck, 5));
	pb(stuck, stuckb);
	write(1, "pb\n", 3);
	move_ra(stuck, get_min_pos(stuck, 4));
	pb(stuck, stuckb);
	write(1, "pb\n", 3);
	sort3(stuck);
	pa(stuck, stuckb);
	pa(stuck, stuckb);
	pa(stuck, stuckb);
	write(1, "pa\npa\npa\n", 9);
}

void	sort_0_6(t_node **stuck, unsigned int size)
{
	t_node	*stuckb;

	if (size == 2)
	{
		if ((*stuck)->value > (*stuck)->next->value)
		{
			sa(stuck);
			write(1, "sa\n", 3);
		}
	}
	else if (size == 3)
		sort3(stuck);
	else if (size == 4)
	{
		move_ra(stuck, get_min_pos(stuck, 4));
		pb(stuck, &stuckb);
		write(1, "pb\n", 3);
		sort3(stuck);
		pa(stuck, &stuckb);
		write(1, "pa\n", 3);
	}
	else if (size == 5)
		sort5(stuck, &stuckb);
	else if (size == 6)
		sort6(stuck, &stuckb);
}
