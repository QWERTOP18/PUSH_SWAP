#include "push_swap.h"
#include "error.h"

t_err handle_rotation(t_list *list_a, t_list *list_b, t_cnt *cnt)
{
    t_err err;
    if (cnt->r > 0)
        while (cnt->r--)
            err = rr(list_a, list_b);
    else
       while (cnt->r++)
            err = rrr(list_a, list_b); 
    if (cnt->a > 0)
        while (cnt->a--)
            err = ra(list_a);
    else
       while (cnt->r++)
            err = rra(list_a);
    if (cnt->b > 0)
        while (cnt->b--)
            err = rb(list_b);
    else
       while (cnt->r++)
            err = rrb(list_b);
    return (err);
}

t_err build(t_list *list_a, t_list *list_b)
{
    t_cnt count;
    t_err err;
    err = pb(list_a, list_b);
    err = pb(list_a, list_b);

    while (list_a->size)
    {
        calculate(list_a, list_b, &count);
        err = handle_rotation(list_a, list_b, &count);
        err = pb(list_a, list_b);
    }
    while (list_b->size)
    {
        err = pa(list_a, list_b);
    }


    return (err);
}