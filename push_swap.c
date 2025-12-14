/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:06:02 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/11 17:06:04 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_push_swap.h"

int	ft_atoi(const char *nptr)
{
	char			sign;
	long long		i;

	sign = 1;
	i = 0;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		i = i * 10 + *nptr - '0';
		nptr++;
	}
	return ((int)(i * sign));
}

void	ft_stuckclear(t_node **stuck)
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

int	is_valid_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	fill_list(t_node **stuck, char **numbers)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (numbers[i])
	{
		if (!is_valid_number(numbers[i]))
		{
			ft_freearray(numbers);
			ft_stuckclear(stuck);
			write(1, "Error\n", 6);
			return (-1);
		}
		tmp = *stuck;
		*stuck = (t_node *)malloc(sizeof(t_node));
		(*stuck)->value = ft_atoi(numbers[i]);
		(*stuck)->next = tmp;
		i++;
	}
	return (ft_freearray(numbers), i);
}

int	main(int argc, char **argv)
{
	t_node	*stuck;
	int 	y;
	int		size;
	
	stuck = NULL;
	size = 0;
	while (--argc > 0)
	{
		y = fill_list(&stuck, ft_split(argv[argc]));
		if (y == -1)
			return (1);
		size += y;
	}
	sort(&stuck, size);
	
	t_node	*tmp;
	tmp = stuck;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}

	ft_stuckclear(&stuck);
	return (0);
}
