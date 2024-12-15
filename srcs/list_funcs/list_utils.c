/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymizukam <ymizukam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:11:02 by ymizukam          #+#    #+#             */
/*   Updated: 2024/12/15 12:16:48 by ymizukam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cyclic_list.h"

void	clst_insert(t_clst *list, const int element)
{
	int	pos;

	pos = list->size;
	while (pos > list->head)
	{
		list->data[pos] = list->data[pos - 1];
		pos--;
	}
	list->data[list->head] = element;
	list->size++;
}

void	clst_remove(t_clst *list)
{
	int	pos;

	pos = list->head;
	while (pos + 1 < list->size)
	{
		list->data[pos] = list->data[pos + 1];
		pos++;
	}
	list->size--;
	if (list->size)
		list->head = list->head % list->size;
}

int	clst_get(const t_clst *list, const int idx)
{
	return (list->data[(list->head + idx + list->size) % list->size]);
}

int	nextid(const t_clst *list)
{
	return ((list->head + 1) % list->size);
}

int	previd(const t_clst *list)
{
	return ((list->head + list->size - 1) % list->size);
}
