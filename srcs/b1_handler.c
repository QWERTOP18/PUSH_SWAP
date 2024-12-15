/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b1_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:01:52 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/15 12:16:18 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_rotation(t_clst *list_a, t_clst *list_b, t_cnt *cnt)
{
	if (cnt->r > 0)
		while (cnt->r-- > 0)
			rr(list_a, list_b);
	else
		while (cnt->r++ < 0)
			rrr(list_a, list_b);
	if (cnt->a > 0)
		while (cnt->a-- > 0)
			ra(list_a);
	else
		while (cnt->a++ < 0)
			rra(list_a);
	if (cnt->b > 0)
		while (cnt->b-- > 0)
			rb(list_b);
	else
		while (cnt->b++ < 0)
			rrb(list_b);
	cnt->a = 0;
	cnt->b = 0;
	cnt->r = 0;
	cnt->total = 0;
}

void	handle_pushb(t_clst *list_a, t_clst *list_b)
{
	while (list_a->size > 3)
	{
		pb(list_a, list_b);
	}
	if (check_sorted(list_a, list_a->head) || check_sorted(list_a,
			previd(list_a)) || check_sorted(list_a, nextid(list_a)))
		return ;
	sa(list_a);
}

void	handle_pusha(t_clst *list_a, t_clst *list_b)
{
	t_cnt	cnt;

	while (list_b->size)
	{
		calculate(list_a, list_b, &cnt);
		handle_rotation(list_a, list_b, &cnt);
		pa(list_a, list_b);
	}
}
