#include "ft_push_swap.h"
#include <stdlib.h>

int main(void)
{
    t_node *a = malloc(sizeof(t_node));
    t_node *b = malloc(sizeof(t_node));
    t_node *c = malloc(sizeof(t_node));
    t_node *d = malloc(sizeof(t_node));
    t_node *e = malloc(sizeof(t_node));
    t_node *f = malloc(sizeof(t_node));

    a->value = 2;
    b->value = 1;
    c->value = 3;
    d->value = 6;
    e->value = 5;
    f->value = 8;

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = NULL;

    t_node *bb = NULL;   // stack B empty

    sa(&a);
	pb(&a, &bb);
	pb(&a, &bb);
	pb(&a, &bb);
    ra(&a);
    rb(&bb);
    rra(&a);
    rrb(&bb);
    sa(&a);
    pa(&a, &bb);
    pa(&a, &bb);
    pa(&a, &bb);
    


    t_node *tmp1 = a;
    t_node *tmp2 = bb;
    for (int i = 0; i < 6; i++)
    {
        if (tmp1)
        {
            ft_printf("%d", tmp1->value);
            tmp1 = tmp1->next;
        }
        else ft_printf(" ");
        ft_printf("  ");
        if (tmp2)
        {
            ft_printf("%d", tmp2->value);
            tmp2 = tmp2->next;
        }
        else ft_printf(" ");
        ft_printf("\n");
    }
    ft_printf("a  b\n");
}
