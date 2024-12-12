#include "push_swap.h"
#include "error.h"

t_err handle_rotation(t_list *list_a, t_list *list_b, t_cnt *cnt)
{
    printf("handle_rotation\n");
    printf("%d %d %d\n", cnt->a, cnt->b, cnt->r);
    return E_NONE;

    //無限ループ？
    // t_err err;
    // if (cnt->r > 0)
    //     while (cnt->r-->0)
    //         err = rr(list_a, list_b);
    // else
    //    while (cnt->r++<0)
    //         err = rrr(list_a, list_b); 
    // if (cnt->a > 0)
    //     while (cnt->a-->0)
    //         err = ra(list_a);
    // else
    //    while (cnt->r++<0)
    //         err = rra(list_a);
    // if (cnt->b > 0)
    //     while (cnt->b-->0)
    //         err = rb(list_b);
    // else
    //    while (cnt->r++<0)
    //         err = rrb(list_b);
    // return (err);
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

int check_sorted(t_list *list, int head)
{
    if (list->size <= 1)
        return (1);

    int i = 0;
    while (i < list->size - 1)
    {
        if (list->data[(i+head)%list->size] > list->data[(i+head+1)%list->size])
            return (0);
        i++;
    }
    return (1);
}


#ifdef TEST_UTILS
#define DEBUG
//cc ../utils/list_funcs/*.c  b1_buildutils.c -DTEST_UTILS -I../includes


void printlst(t_list *list)
{
    printf("--->list<---\n");
    for (size_t i = 0; i < list->size; i++)
    {
        printf("%d ",list->data[(list->head+i)%list->size]);
    }
    printf("\n");
    
}


int main(int argc, char const *argv[])
{
    t_list list_a;
    t_list list_b;
    lstalloc(&list_a,5,5);
    lstalloc(&list_b,0,5);
    for (size_t i = 0; i < 5; i++)
    {
        list_a.data[i] = (i+2)%5;
    }
    printlst(&list_a);
    printlst(&list_b);

    printf("check %d\n",check_sorted(&list_a,list_a.head));
    alignby_rotate(&list_a);
    printf("check %d\n",check_sorted(&list_a,list_a.head));
    printlst(&list_a);
    printlst(&list_b);

    lstfree(&list_a);
    lstfree(&list_b);
    return 0;
}
#endif