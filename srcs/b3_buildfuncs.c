/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b3_buildfuncs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 22:44:25 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/14 22:46:14 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "push_swap.h"

int	select_direction(int idx, int list_size)
{
	if (2 * idx > list_size)
	{
		return (idx - list_size);
	}
	return (idx);
}

t_err	alignby_rotate(t_clst *list)
{
	t_err	err;
	int		dist;
	int		min_val;
	int		idx;

	dist = 0;
	min_val = INT_MAX;
	idx = 0;
	while (idx < list->size)
	{
		if (list->data[idx] < min_val)
		{
			min_val = list->data[idx];
			dist = (idx - list->head + list->size) % list->size;
		}
		idx++;
	}
	dist = select_direction(dist, list->size);
	if (dist > 0)
	{
		while (dist--)
			err = ra(list);
	}
	else
	{
		while (dist++)
			err = rra(list);
	}
	return (err);
}

int	check_sorted(t_clst *list, int head)
{
	int	i;

	if (list->size <= 1)
		return (1);
	i = 0;
	while (i < list->size - 1)
	{
		if (list->data[(i + head) % list->size] > list->data[(i + head + 1)
			% list->size])
		{
			return (0);
		}
		i++;
	}
	return (1);
}
