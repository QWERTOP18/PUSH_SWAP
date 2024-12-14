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
    printf("exit with %d\n", status);
    if(status == E_NONE)
        exit(0);
    write(2,"Error\n",6);
    exit(status);
}
t_err	build(t_clst *list_a, t_clst *list_b)
{

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



int main(int argc,char **argv)
{
    t_clst *list_a;
    t_clst *list_b;
    if (argc == 1)
        return 0;
    list_a = format_input(argc,argv);
    if(!list_a)
       ft_exit(E_ALLOCATE); 
    list_b = clst_new(list_a->capacity);
    if(!list_b)
       ft_exit(E_ALLOCATE);
    if(build(list_a, list_b))
        ft_exit(E_OPERATION);
    clst_clear(list_a);
    clst_clear(list_b);
    return E_NONE;
}

