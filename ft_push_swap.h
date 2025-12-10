
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "printf/ft_printf.h"

typedef struct s_node
{
    int             value;
    int             index;
    struct s_node   *next;
}   t_node;

void    pa(int *a, int *b, unsigned int size);
void    pb(int *a, int *b, unsigned int size);

void    rra(int *a, unsigned int size);
void    rrb(int *b, unsigned int size);

void    rrr(int *a, int *b, unsigned int size);
void    ra(int *a, unsigned int size);
void    rb(int *b, unsigned int size);

void    sa(int *a, unsigned int size);
void    sb(int *b, unsigned int size);
void    ss(int *a, int *b, unsigned int size);

#endif