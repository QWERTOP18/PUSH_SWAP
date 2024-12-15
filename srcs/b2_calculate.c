/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b2_calculate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:38:56 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/14 22:42:50 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "push_swap.h"



int	find_insert_idx(const t_clst *list_a, const t_clst *list_b, int idx_b)
{
	int	idx_a;
	int	curr_a;
	int	prev_a;
	int	elem_b;

	idx_a = 0;
	elem_b = list_b->data[(list_b->head + idx_b) % list_b->size];
	while (idx_a < list_a->size)
	{
		curr_a = clst_get(list_a,idx_a);
		prev_a = clst_get(list_a,idx_a-1);
		if (prev_a < elem_b && elem_b < curr_a)
			return (idx_a);
		if (prev_a > curr_a)
			if (elem_b < curr_a || prev_a < elem_b)
				return (idx_a);
		idx_a++;
	}
	return (idx_a);
}

void optimize_cnt(t_cnt *cnt)
{
	cnt->total = ft_max(ft_abs(cnt->a),ft_abs(cnt->b));
	if (cnt->a > 0 && cnt->b > 0)
	{
		cnt->r = ft_min(cnt->a, cnt->b);
		cnt->a -= cnt->r;
		cnt->b -= cnt->r;
	}
	else if (cnt->a < 0 && cnt->b < 0)
	{
		cnt->r = ft_max(cnt->a, cnt->b);
		cnt->a -= cnt->r;
		cnt->b -= cnt->r;
	}
	else
		cnt->total = ft_abs(cnt->a - cnt->b);
}
void	update_cnt(t_cnt *tmp, t_cnt *ret)
{
	static int	min_total;


	if (tmp->b == 0)
	{
		min_total = INT_MAX;
	}
	optimize_cnt(tmp);
	if (tmp->total < min_total)
	{
		min_total = tmp->total;
		*ret = *tmp;
	}
}

void	calculate(t_clst *list_a, t_clst *list_b, t_cnt *ret_cnt)
{
	int		idx_b;
	t_cnt	tmp_cnt;

	idx_b = 0;
	while (idx_b < list_b->size)
	{
		tmp_cnt.a = find_insert_idx(list_a, list_b, idx_b);
		tmp_cnt.a = select_direction(tmp_cnt.a, list_a->size);
		tmp_cnt.b = select_direction(idx_b, list_b->size);
		tmp_cnt.r = 0;
		update_cnt(&tmp_cnt, ret_cnt);
		idx_b++;
	}
}
