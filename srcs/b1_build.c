#include "push_swap.h"


void handle_pushb(t_list *list_a, t_list *list_b)
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

void handle_pusha(t_list *list_a, t_list *list_b)
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
    handle_pushb(list_a, list_b);
    handle_pusha(list_a, list_b);
    
    alignby_rotate(list_a);
    if (check_sorted(list_a,list_a->head))
        return E_NONE;
    else
        return E_OPERATION;
}


#ifdef TEST_PUSHB
#define DEBUG
//cc ../utils/list_funcs/*.c  b1_*.c -DTEST_PUSHB -I../includes
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
    int size = 3;
    lstalloc(&list_a,size,size);
    lstalloc(&list_b,0,size);
    for (size_t i = 0; i < size; i++)
    {
        list_a.data[i] = (i+7)%4;
    }
    sa(&list_a);
    printlst(&list_a);
    printlst(&list_b);

    handle_pushb(&list_a,&list_b);
    
    printlst(&list_a);
    printlst(&list_b);

    lstfree(&list_a);
    lstfree(&list_b);
    return 0;
}
#endif

#ifdef TEST_PUSHA
#define DEBUG
//cc ../utils/list_funcs/*.c  b1_*.c -DTEST_PUSHA -I../includes
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
    int size = 6;
    lstalloc(&list_a,size,size);
    lstalloc(&list_b,0,size);
    for (size_t i = 0; i < size; i++)
    {
        list_a.data[i] = (size-i+1);
    }
    printlst(&list_a);
    printlst(&list_b);
    handle_pushb(&list_a,&list_b);
    handle_pusha(&list_a,&list_b);
    
    printlst(&list_a);
    printlst(&list_b);

    lstfree(&list_a);
    lstfree(&list_b);
    return 0;
}
#endif