/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:19:58 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/17 15:20:06 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap_bonus.h"

static int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((*s1 || *s2) && i < n)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
		i++;
	}
	return (0);
}

static int	execute_operation(t_node **stucka, t_node **stuckb, char *operation)
{
	if (!ft_strncmp("pa\n", operation, 3))
		return (pa(stucka, stuckb), 1);
	else if (!ft_strncmp("pb\n", operation, 3))
		return (pb(stucka, stuckb), 1);
	else if (!ft_strncmp("sa\n", operation, 3))
		return (sa(stucka), 1);
	else if (!ft_strncmp("sb\n", operation, 3))
		return (sb(stuckb), 1);
	else if (!ft_strncmp("ss\n", operation, 3))
		return (ss(stucka, stuckb), 1);
	else if (!ft_strncmp("ra\n", operation, 3))
		return (ra(stucka), 1);
	else if (!ft_strncmp("rb\n", operation, 3))
		return (rb(stuckb), 1);
	else if (!ft_strncmp("rr\n", operation, 3))
		return (rr(stucka, stuckb), 1);
	else if (!ft_strncmp("rra\n", operation, 4))
		return (rra(stucka), 1);
	else if (!ft_strncmp("rrb\n", operation, 4))
		return (rrb(stuckb), 1);
	else if (!ft_strncmp("rrr\n", operation, 4))
		return (rrr(stucka, stuckb), 1);
	return (0);
}

static int	is_sorted(t_node *stuck)
{
	while (stuck)
	{
		if (stuck->next && stuck->value > stuck->next->value)
			return (0);
		stuck = stuck->next;
	}
	return (1);
}

int	sort(t_node **stuck)
{
	t_node	*stuckb;
	int		i;
	int		index;
	char	operation[5];

	index = 0;
	while (1)
	{
		if (index >= 5)
			return (-1);
		i = read(1, &operation[index], 1);
		if (i < 1)
			break ;
		if (operation[index] == '\n')
		{
			if (!execute_operation(stuck, &stuckb, operation))
				return (-1);
			index = 0;
		}
		else
			index++;
	}
	if (is_sorted(*stuck))
		return (1);
	return (0);
}
