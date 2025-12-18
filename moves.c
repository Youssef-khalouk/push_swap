/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <ykhalouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 13:57:33 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/18 16:21:25 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_sorted(t_node *stuck)
{
	while (stuck)
	{
		if (stuck->next && stuck->value > stuck->next->value)
			return (0);
		stuck = stuck->next;
	}
	return (1);
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
