#include "push_swap.h"

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

int find_insert_idx(t_list *list_a, t_list *list_b, int idx_b)
{
    int idx_a = 0;
    int curr_a;
    int prev_a;
    int elem_b = list_b->data[(list_b->head + idx_b) % list_b->size];
    while (idx_a < list_a->size)
    {
        curr_a = list_b->data[(list_b->head + idx_b) % list_b->size];
        prev_a = list_b->data[(list_b->head + idx_b - 1 + list_b->size) % list_b->size]; 
        // if (curr_a < elem_b && elem_b < prev_a)
        //     return idx_a;
        // //輪っかの切れ目
        // if (prev_a < curr_a)
        //     if (elem_b < prev_a || curr_a < elem_b)
        //     return idx_a;
        if (curr_a > elem_b && elem_b > prev_a)
            return idx_a;
        //輪っかの切れ目
        if (prev_a > curr_a)
            if (elem_b > prev_a || curr_a > elem_b)
            return idx_a;
        idx_a++;
    }
    //list_b->size=0の時もここに入る
    return idx_a;
}

void update_cnt(t_cnt *tmp,t_cnt *ret)
{
    static int min_total;
    //calculateが呼び出されるたびに初期化
    if (tmp->b==0)
        min_total = INT_MAX;
    int tmp_total = optimize_cnt(tmp);
    if (tmp_total < min_total)
    {
        min_total = tmp_total;
        *ret = *tmp;
        //ret = tmp? 一括代入できる？
    }
}

/*
*構造体の一括代入はできる？return valueとして構造体を返したいが
*呼び出し側の初期化が大変そう
*/
void calculate(t_list *list_a, t_list *list_b,t_cnt *ret_cnt)
{
    
    int idx_b = 0;
    t_cnt tmp_cnt;
    
    while (idx_b < list_b->size)
    {
        tmp_cnt.a = find_insert_idx(list_a, list_b, idx_b);
        tmp_cnt.a = select_direction(idx_b,list_a->size);
        tmp_cnt.b = select_direction(tmp_cnt.b,list_b->size);
        update_cnt(&tmp_cnt,ret_cnt);
        idx_b++;
    }
}
