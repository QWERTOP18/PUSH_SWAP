#include "push_swap.h"

/*
*main->build
*Aに3個残してpa
*Aが昇順になるようにしながらpb
*Aを回転

size=1 check_sortedでreturn
size=2 alignby_rotate
size=3
*/
t_err	build(t_list *list_a, t_list *list_b)
{
	t_cnt	count;

	if (check_sorted(list_a, list_a->head))
		return (E_NONE);
	handle_pushb(list_a, list_b);
	handle_pusha(list_a, list_b);
	alignby_rotate(list_a);
	if (check_sorted(list_a, list_a->head))
		return (E_NONE);
	else
		return (E_OPERATION);
}
