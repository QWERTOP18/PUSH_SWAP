#include "push_swap.h"
#include "error.h"

t_err build(t_list *list_a, t_list *list_b)
{
    t_cnt count;
    t_err err;

    if (check_sorted(list_a))
        return E_NONE;
    // if (list_a->size <= 6)
    //     return(build_tinycase(list_a, list_b));
    err = pb(list_a, list_b);
    err = pb(list_a, list_b);
    while (list_a->size)
    {
        calculate(list_a, list_b, &count);
        //count = calculate(list_a, list_b); 
        err = handle_rotation(list_a, list_b, &count);
        err = pb(list_a, list_b);
    }
    while (list_b->size)
    {
        err = pa(list_a, list_b);
    }
    err = alignby_rotate(list_a);
    return (err);
}