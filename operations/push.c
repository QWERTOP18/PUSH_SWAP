/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 19:56:15 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/08 20:03:46 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

int	push(t_list *list_from, t_list *list_to)
{
	if (list_from->size < 1)
	{
		return (1);
	}
	return (0);
}

int	pa(t_list *list_a, t_list *list_b)
{
	if (push(list_a, list_b))
	{
		return (1);
	}
	ft_printf("pa\n");
	return (0);
}

int	pb(t_list *list_a, t_list *list_b)
{
	if (push(list_b, list_a))
	{
		return (1);
	}
	ft_printf("pb\n");
	return (0);
}

#ifdef TEST_PUSH
#endif