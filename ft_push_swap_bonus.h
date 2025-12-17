/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 15:21:56 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/17 15:21:59 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_BONUS_H
# define FT_PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

int			sort(t_node **stuck);

void		ft_freearray(char **array);
char		**ft_split(char const *s);

void		pa(t_node **a, t_node **b);
void		pb(t_node **a, t_node **b);

void		ra(t_node **a);
void		rb(t_node **b);
void		rr(t_node **a, t_node **b);

void		rra(t_node **a);
void		rrb(t_node **b);
void		rrr(t_node **a, t_node **b);

void		sa(t_node **a);
void		sb(t_node **b);
void		ss(t_node **a, t_node **b);

long long	ft_atoi(const char *nptr);

#endif