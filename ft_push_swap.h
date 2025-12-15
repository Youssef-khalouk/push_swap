/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhalouk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:06:13 by ykhalouk          #+#    #+#             */
/*   Updated: 2025/12/11 17:06:21 by ykhalouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_moves
{
	int	a;
	int	b;
	int	ab;
}	t_moves;

void	ft_freearray(char **array);
char	**ft_split(char const *s);

void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);

void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);

void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);

t_node	*initalize_stuck_b(t_node **stuck);

int		get_rotations(t_node **stuckb, int value, int size);

t_moves	get_moves(t_node *stucka, t_node **stuckb, int a_size, int b_size);

void	sort(t_node **stuck, unsigned int size);

void    sort_0_6(t_node **stuck, unsigned int size);

void	move_ra(t_node **stuck, int times);

#endif
