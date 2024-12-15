/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:36:55 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/15 12:16:26 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

int	reverse_rotate(t_clst *list)
{
	if (list->size < 1)
	{
		return (1);
	}
	list->head = previd(list);
	return (0);
}

int	rra(t_clst *list_a)
{
	if (reverse_rotate(list_a))
	{
		return (1);
	}
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_clst *list_b)
{
	if (reverse_rotate(list_b))
	{
		return (1);
	}
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_clst *list_a, t_clst *list_b)
{
	if (reverse_rotate(list_a) || reverse_rotate(list_b))
	{
		return (1);
	}
	write(1, "rrr\n", 4);
	return (0);
}
