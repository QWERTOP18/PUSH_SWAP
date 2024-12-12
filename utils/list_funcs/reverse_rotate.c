/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:36:55 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/12 15:12:30 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

int	reverse_rotate(t_list *list)
{
	if (list->size < 1)
	{
		return (1);
	}
	list->head = previd(list);
	return (0);
}

int	rra(t_list *list_a)
{
	if (reverse_rotate(list_a))
	{
		return (1);
	}
	ft_printf("rra\n");
	return (0);
}

int	rrb(t_list *list_b)
{
	if (reverse_rotate(list_b))
	{
		return (1);
	}
	ft_printf("rrb\n");
	return (0);
}

int	rrr(t_list *list_a, t_list *list_b)
{
	if (reverse_rotate(list_a) || reverse_rotate(list_b))
	{
		return (1);
	}
	ft_printf("rrr\n");
	return (0);
}
