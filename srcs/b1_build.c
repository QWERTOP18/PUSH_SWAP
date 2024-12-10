#include "push_swap.h"
#include "error.h"

// t_err build(t_list *list_a, t_list *list_b)
// {
//     t_cnt count;
//     t_err err;

//     if (check_sorted(list_a))
//         return E_NONE;
    

//     // if (list_a->size <= 6)
//     //     return(build_tinycase(list_a, list_b));
//     // err = pb(list_a, list_b);
//     // err = pb(list_a, list_b);
//     while (list_a->size)
//     {
//         calculate(list_a, list_b, &count);
//         //count = calculate(list_a, list_b); 
//         err = handle_rotation(list_a, list_b, &count);
//         err = pb(list_a, list_b);
//     }
//     while (list_b->size)
//     {
//         err = pa(list_a, list_b);
//     }
//     err = alignby_rotate(list_a);
//     return (err);
// }
void handle_push_ab(t_list *list_a, t_list *list_b)
{
    //3個残してpb 
    //余裕あればLISの計算
    while(list_a->size > 3)
    {
        pb(list_a, list_b);   
    }
    //swap
    //find__insert_idxと同じだから関数かできそう
    if (check_sorted(list_a,list_a->head) || check_sorted(list_a,previd(list_a)) || check_sorted(list_a,nextid(list_a)))
        return;
    sa(list_a);   
}

void handle_push_ba(t_list *list_a, t_list *list_b)
{
    t_cnt count;

    while (list_b->size)
    {
        calculate(list_a, list_b, &count);
        //count = calculate(list_a, list_b); 
        handle_rotation(list_a, list_b, &count);
        pa(list_a, list_b);
    }
}
/*
*main->build 
*Aに3個残してpa
*Aが昇順になるようにしながらpb
*Aを回転

size=1 check_sortedでreturn
size=2 alignby_rotate
size=3 
*/
t_err build(t_list *list_a, t_list *list_b)
{
    t_cnt count;

    if (check_sorted(list_a,list_a->head))
        return E_NONE;
    handle_push_ab(list_a, list_b);
    handle_push_ba(list_a, list_b);
    
    alignby_rotate(list_a);
    if (check_sorted(list_a,list_a->head))
        return E_NONE;
    else
        return E_OPERATION;
}