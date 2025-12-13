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



static int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

static void	calculate_best_move(int *a, int *b, int *ab)
{
	int	common;

	if (ft_abs(*a) < ft_abs(*b))
		common = ft_abs(*a);
	else
		common = ft_abs(*b);
	if (*a > 0)
		*ab = common;
	else
		*ab = -common;
	*a -= *ab;
	*b -= *ab;
}

static int	set_new_move(t_moves *moves, int ta, int tb, int tab)
{
	moves->a = ta;
	moves->b = tb;
	moves->ab = tab;
	return (ft_abs(tb) + ft_abs(ta) + ft_abs(tab));
}

t_moves	get_moves(t_node *stucka, t_node **stuckb, int a_size, int b_size)
{
	t_moves	moves;
	int		rotations;
	t_moves	tmp_m;
	int		i;

	rotations = 2147483647;
	i = 0;
	tmp_m.ab = 0;
	while (stucka)
	{
		tmp_m.a = (i <= a_size / 2) * i + (i > a_size / 2) * (i - a_size);
		tmp_m.b = get_rotations(stuckb, stucka->value, b_size);
		if ((tmp_m.a > 0 && tmp_m.a > 0) || (tmp_m.a < 0 && tmp_m.a < 0))
			calculate_best_move(&tmp_m.a, &tmp_m.b, &tmp_m.ab);
		if ((ft_abs(tmp_m.b) + ft_abs(tmp_m.a) + ft_abs(tmp_m.ab)) < rotations)
			rotations = set_new_move(&moves, tmp_m.a, tmp_m.b, tmp_m.ab);
		stucka = stucka->next;
		i++;
	}
	return (moves);
}



static t_node	*initalize_stuck_b(t_node **stuck)
{
	t_node	*tmp;

	tmp = NULL;
	pb(stuck, &tmp);
	pb(stuck, &tmp);
	if (tmp->value < tmp->next->value)
		rb(&tmp);
	return (tmp);
}

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

static void	move_ra(t_node **stuck, int times)
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
