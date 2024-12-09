#include "push_swap.h"
#include "error.h"
#include <limits.h>


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
    return (max(cnt->a - cnt->b , cnt->b - cnt->a));
}
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
        //todo
        // if ((num > current->num && num < prev) || (num > current->num
		// 		&& prev < current->num) || (prev < current->num && num < prev))
		// {
		// 	return (idx_b);
		// }
        idx_b++;
    }



    return idx_b;

}

int select_direction(int idx, int list_size)
{
    if (2*idx > list_size)
    {
        return idx - list_size;
    }
    return idx;
}


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