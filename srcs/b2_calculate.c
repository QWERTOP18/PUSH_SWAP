#include "push_swap.h"
#include "error.h"
#include <limits.h>


void update_cnt(t_cnt *tmp,t_cnt *ret)
{
    static int min_total;
    //calculateが呼び出されるたびに初期化
    if (tmp->a==0)
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
    
    int idx_a = 0;
    t_cnt tmp_cnt;
    
    while (idx_a < list_a->size)
    {
        tmp_cnt.b = find_insert_idx(list_a, list_b, idx_a);
        tmp_cnt.a = select_direction(idx_a,list_a->size);
        tmp_cnt.b = setlect_direction(tmp_cnt.b,list_b->size);
        update_cnt(&tmp_cnt,ret_cnt);
        idx_a++;
    }
}