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
int select_direction(int idx, int list_size)
{
    if (2*idx > list_size)
    {
        return idx - list_size;
    }
    return idx;
}
/*
*dist:= headと最小値までの距離
*/
t_err alignby_rotate(t_list *list)
{
   t_err err;
   int dist = 0;
   int min_val = INT_MAX;
   int idx = 0;
   while(idx < list->size)
   {
     if(list->data[idx] < min_val)
     {
         min_val = list->data[idx];
         dist = (idx - list->head + list->size) % list->size;
     }
     idx++;
   }
   dist = select_direction(dist, list->size);
   if(dist > 0)
   {
       while (dist--)
           err = ra(list);
   }
   else
    {
        while(dist++)
        err = rra(list);
    }
    return err;
}

int check_sorted(t_list *list)
{
    int i = 0;
    while (i < list->size - 1)
    {
        if (list->data[i] > list->data[i + 1])
            return (1);
        i++;
    }
    return (0);
}
