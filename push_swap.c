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

int	main(int argc, char **argv)
{
	int		i;
	t_node	*stuck;
	t_node	*tmp;

	i = argc - 1;
	stuck = NULL;
	while (i > 0)
	{
		tmp = stuck;
		stuck = (t_node *)malloc(sizeof(t_node));
		if (!is_valid_number(argv[i]))
		{
			ft_stuckclear(&stuck);
			write(1, "Error\n", 6);
			return (1);
		}
		stuck->value = ft_atoi(argv[i]);
		stuck->next = tmp;
		i--;
	}
	sort(&stuck, argc - 1);
	tmp = stuck;
	// while (tmp)
	// {
	// 	ft_printf("%d\n", tmp->value);
	// 	tmp = tmp->next;
	// }
	ft_stuckclear(&stuck);
	return (0);
}
