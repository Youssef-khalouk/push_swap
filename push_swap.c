/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <ykhalouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:06:02 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/18 13:48:16 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	ft_stuckclear(t_node **stuck)
{
	t_node	*tmp;

	if (!stuck || !*stuck)
		return ;
	while (*stuck)
	{
		tmp = *stuck;
		*stuck = tmp->next;
		free(tmp);
	}
}

static int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	return (1);
}

static int	fill_list(t_node **stuck, char **numbers)
{
	int			i;
	long long	n;
	t_node		*tmp;
	int			size;

	i = 0;
	size = 0;
	if (*numbers == NULL)
		return (ft_freearray(numbers), -1);
	while (numbers[i])
		i++;
	while (--i >= 0)
	{
		n = ft_atoi(numbers[i]);
		if (!is_valid_number(numbers[i]) || n > 2147483647 || n < -2147483648)
			return (ft_freearray(numbers), -1);
		tmp = *stuck;
		*stuck = (t_node *)malloc(sizeof(t_node));
		(*stuck)->value = (int)n;
		(*stuck)->next = tmp;
		size++;
	}
	return (ft_freearray(numbers), size);
}

static int	check_double(t_node *stuck)
{
	t_node	*tmp;
	int		value;

	tmp = stuck;
	while (stuck)
	{
		tmp = stuck->next;
		value = stuck->value;
		while (tmp)
		{
			if (value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		stuck = stuck->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*stuck;
	int		y;
	int		size;

	stuck = NULL;
	size = 0;
	while (--argc > 0)
	{
		y = fill_list(&stuck, ft_split(argv[argc]));
		if (y == -1)
			break ;
		size += y;
	}
	if (y == -1 || check_double(stuck))
		return (write(2, "Error\n", 6), ft_stuckclear(&stuck), 1);
	if (size <= 6)
		sort_0_6(&stuck, size);
	else
		sort(&stuck, size);
	ft_stuckclear(&stuck);
	return (0);
}
