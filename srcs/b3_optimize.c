#include "push_swap.h"
#include "error.h"
int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;    
}
int abs(int a)
{
    if (a < 0)
        return -a;
    return a;   
}
/*
*rotate a,b,r(ab)の回数を最適化して
*合計回数を返す
*/
int optimize_cnt(t_cnt *cnt)
{
    if (cnt->a > 0 && cnt->b > 0)
    {
        cnt->r = min(cnt->a, cnt->b);
        cnt->a -= cnt->r;
        cnt->b -= cnt->r;
        return (cnt->a + cnt->b - cnt->r);
    }
    if (cnt->a < 0 && cnt->b < 0)
    {
        cnt->r = max(cnt->a,cnt->b);
        cnt->a += cnt->r;
        cnt->b += cnt->r;
        return (-(cnt->a + cnt->b - cnt->r));
    }
    cnt->r = 0;
    return (abs(cnt->a - cnt->b));
}

int find_insert_idx(t_list *list_a, t_list *list_b, int idx_a)
{
    int idx_b = 0;
    int curr_b;
    int prev_b;
    int elem_a = list_a->data[(list_a->head + idx_a) % list_a->size];
    while (idx_b < list_b->size)
    {
        curr_b = list_b->data[(list_b->head + idx_b) % list_b->size];
        prev_b = list_b->data[(list_b->head + idx_b - 1 + list_b->size) % list_b->size]; 
        if (curr_b < elem_a && elem_a < prev_b)
            return idx_b;
        //輪っかの切れ目
        if (prev_b < curr_b)
            if (elem_a < prev_b || curr_b < elem_a)
            return idx_b;
        idx_b++;
    }
    //list_b->size=0の時もここに入る
    return idx_b;
}


