/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:06:45 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/08 20:50:44 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "error.h"

//memory leakしたらlst_a,kst_bを引数にとる
void ft_exit(int status)
{
    write(2,"Error\n",6);
    exit(0);
}
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
int main(int argc,char **argv) {
    t_list *list_a;
    t_list *list_b;
    if (argc == 1)
        return 0;
    list_a = format_input(argc,argv);
    if(!list_a)
       ft_exit(E_ALLOCATE); 
    list_b = lst_alloc(list_a->capacity);
    if(!list_b)
       ft_exit(E_ALLOCATE);
    if(build(list_a, list_b))
        ft_exit(E_OPERATION);
    lst_clear(list_a);
    lstclear(list_b);
    return E_NONE;
    //ft_exit(E_NONE);
}

