#include "push_swap.h"
#include "error.h"
#include <limits.h>





void update_cnt(t_cnt *tmp)
{
    static int min_total = INT_MAX;
    if (tmp->a==0)
        min_total = INT_MAX;
}
t_err calculate(t_list *list_a, t_list *list_b,t_cnt *cnt)
{
    
    int idx_a = 0;
    t_cnt tmp_cnt;
    
    while (idx_a < list_a->size)
    {
        tmp_cnt.b = find_insert_idx(list_a, list_b, idx_a);

        update_cnt(&tmp_cnt);
        idx_a++;
    }
    
}